#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif  
    int t,x;
    cin>>t;
    for(x=1;x<=t;x++)
    {
        long k,i,j,c=0;
        cin>>k;
        long a[k];
        for(i=0;i<k;i++)
        {
            cin>>a[i];
        }
        long inc=3,dec=3;
        for(i=0;i<k-1;i++)
        {
            if(a[i]<a[i+1])
            {
                if(inc==0)
                {
                    c++;
                    inc=4;
                }
                inc--;
                dec=3;
            }
            else if(a[i]>a[i+1])
            {
                if(dec==0)
                {
                    c++;
                    dec=4;
                }
                dec--;
                inc=3;
            }
        }
       // cout<<inc<<" "<<dec<<" "<<a[i]<<" "<<a[i-1]<<endl;
        /*if(a[i]>a[i-1])
        {
            if(inc==0)
            {
                c++;
            }
        }
        else if(a[i]<a[i+1])
        {
            if(dec==0)
            {
                c++;
            }
        }*/
        cout<<"Case #"<<x<<": "<<c<<endl;
    }
}
