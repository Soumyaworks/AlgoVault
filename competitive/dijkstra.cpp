#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("Ofast")
#define ll long long int
#define pb push_back
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define mod 1000000007
#define fill(a,x) memset(a,x,sizeof(a))
#define indexed_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
using namespace __gnu_pbds;


//Dijkstra Algorithm
//Consider edges[v][3], edges[v][0]--->edges[v][1], edges[v][2]=length of the path
//Consider 0-based vertices and indices everywhere
//Source is 1-based
//Returns the distance array from source--->all vertices ,excluding the source one
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {

    int i,j,k,c;
    s--;
    vector<bool>used(n,false);
    vector<int>d(n,INT_MAX);
    vector<int>p(n,-1);
    d[s]=0;
    for(i=0;i<n;i++)
    {
        int m=INT_MAX,v;
        for(j=0;j<n;j++)
        {
            if(!used[j] && d[j]<=m)
            {
                v=j;
                m=d[j];
            }
        }
        //cout<<"v="<<v<<"\n";
        used[v]=true;
        
        if(d[v]==INT_MAX)
        {
            d[v]=-1;
            continue;
        }
        
        for(j=0;j<edges.size();j++)
        {
            if(v==edges[j][0]) //Vertex v is the source, i.e edges[j][0]
            {
                int to=edges[j][1];
                int len=edges[j][2];
                if((d[v]+len) < d[to])
                {
                    //cout<<"Changed to="<<to<<":"<<(d[v]+len)<<"\n";
                    d[to]=d[v]+len;
                    p[to]=v;
                }
            }
            else if(v==edges[j][1]) //Vertex v is the destination, i.e edges[j][1]
            {
                int to=edges[j][0];
                int len=edges[j][2];
                if((d[v]+len) < d[to])
                {
                    //cout<<"Changed to="<<to<<":"<<(d[v]+len)<<"\n";
                    d[to]=d[v]+len;
                    p[to]=v;
                }
            }
        }
    }
    vector<int>d1(n-1);
    k=0;
    for(i=0;i<n;i++)
    {
        if(d[i]==0)
        continue;
        else
        d1[k++]=d[i];
    }
    return d1;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    //cout<<"Hello World"<<"\n";
    
    return 0;
}