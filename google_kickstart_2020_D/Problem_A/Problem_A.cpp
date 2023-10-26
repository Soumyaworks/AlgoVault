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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    //cout<<"Hello World"<<"\n";
    int tt,t,n,i,j,k,c,p;
    cin>>t;
    tt=0;
    while(t--)
    {
        tt++;
        cin>>n;
        int v[n];
        for(i=0;i<n;i++)
        cin>>v[i];
        if(n==1)
        cout<<"Case #"<<tt<<": "<<1<<"\n";     
        else
        {
            c=v[0];
            p=0;
            for(i=0;i<n;i++)
            {
                if(i==0)
                {
                    if(i<n-1 && v[i]>v[i+1])
                    p++;
                }
                else if(i==n-1)
                {
                    if(v[i]>c)
                    {
                        c=v[i];
                        p++;
                    }
                }
                else
                {
                    if(v[i]>c)
                    {
                        c=v[i];
                        if(v[i]>v[i+1])
                        p++;
                    }
                }
                
 
            }  
            cout<<"Case #"<<tt<<": "<<p<<"\n";     
        }
    }
    return 0;
}