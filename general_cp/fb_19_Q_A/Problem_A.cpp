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
    int t,n,i,j,k,c,p,tt=0;
    cin>>t;
    while(t--)
    {
        tt++;
        string s;
        cin>>s;
        int f=0;
        n=s.length();
        if(n==1)
        cout<<"Case #"<<tt<<": "<<"Y"<<"\n";
        else
        {
            k=0;
            for(i=0;i<n;i++)
            {
                if(s[i]=='B')
                k++;
            }
            if(k==0 || (k==n-1))
            cout<<"Case #"<<tt<<": "<<"N"<<"\n";
            else
            {
                k--;
                if(k>=((n-2)/2))
                cout<<"Case #"<<tt<<": "<<"Y"<<"\n";
                else
                {
                    cout<<"Case #"<<tt<<": "<<"N"<<"\n";
                }
                
            }
            
        }
        
        
    }
    return 0;
}