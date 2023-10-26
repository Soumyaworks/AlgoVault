#include<bits/stdc++.h>
#include<mpi.h>
using namespace std;

int calculateValue(double x,double y,int k)
{
    int i,j;
    float a=0,b=0;
    for(i=0;i<k;i++)
    {
        float tempX = a*a - b*b + x;
        float tempY = 2*a*b + y;
        a = tempX;
        b = tempY;
        float res = tempX*tempX + tempY*tempY;
        if(res > 4.0)
        {
            return 0;
        }
    }
    return 1;
}


int main(int argc, char* argv[])
{
    int m=16,n=16,k=1000;
    MPI_Init(&argc, &argv);
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int p = size-1;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    float flattenedMRow[m*n],flattenedMCol[m*n];
    int pointsPerProcess = (m*n)/p;
    int pointsLastProcess = pointsPerProcess + (m*n)%p;
    int pointsPerProcessArr[p+1];
    int displacementsProcessArr[p+1];
    float tempBufferRow[pointsLastProcess],tempBufferCol[pointsLastProcess];
    float mandelbrotValues[m*n];
    
    if(rank == 0)
    {
        // cout<<rank<<endl;
        double maxX = 1,minX = -1.5,maxY = 1,minY = -1;
        double diffX = (maxX-minX)/(n-1);
        double diffY = (maxY-minY)/(m-1);
        double i,j;
        int isPresent;
        int c = 0;
        pointsPerProcessArr[0] = 0;
        displacementsProcessArr[0] = 0;
        for(int itr=1;itr<=p;itr++)
        {
            pointsPerProcessArr[itr] = pointsPerProcess;
            displacementsProcessArr[itr] = itr*pointsPerProcess;
        } 
        pointsPerProcessArr[p] = pointsLastProcess;
        displacementsProcessArr[p] = (p)*pointsPerProcess;

        cout<<"---------------------------"<<endl;
        cout<<"PointsPerProcessArr"<<endl;
        for(int itr=0;itr<=p;itr++)
        {
            cout<<pointsPerProcessArr[itr]<<" ";
        }
        cout<<endl<<"---------------------------"<<endl;
                // Generate the coordinates of all points
        for(j=maxY; j>=minY; j-=diffY)
        {
            for(i=minX; i<=maxX; i+=diffX)
            {
                flattenedMRow[c] = i;
                flattenedMCol[c] = j;
                c++;
            }
        }
        // Scatter the coordinates of the points among all processes
        MPI_Scatterv(flattenedMRow, pointsPerProcessArr, displacementsProcessArr, MPI_FLOAT, tempBufferRow, pointsLastProcess, MPI_FLOAT, 0, MPI_COMM_WORLD);
        MPI_Scatterv(flattenedMCol, pointsPerProcessArr, displacementsProcessArr, MPI_FLOAT, tempBufferCol, pointsLastProcess, MPI_FLOAT, 0, MPI_COMM_WORLD);
        // Calculate the mandelbrot value for each point and store in an array
        for(int i = 0; i < pointsLastProcess; i++)
        {
            mandelbrotValues[i] = calculateValue(tempBufferRow[i], tempBufferCol[i], k);
        }
        // Gather the mandelbrot values from all processes to the root process
        MPI_Gatherv(mandelbrotValues, pointsLastProcess, MPI_FLOAT, mandelbrotValues, pointsPerProcessArr, displacementsProcessArr, MPI_FLOAT, 0, MPI_COMM_WORLD);
        // Print the final mandelbrot set
        if(rank == 0)
        {
            int index = 0;
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cout<<mandelbrotValues[index++]<<" ";
                }
                cout<<endl;
            }
        }
    }
    MPI_Finalize();
    return 0;
}

