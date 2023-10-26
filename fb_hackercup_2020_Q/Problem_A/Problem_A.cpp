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
        cin>>n;
        string s1,s2;
        cin>>s1;
        cin>>s2;
        char mat[n][n];
        int f=0;
        for(i=0;i<n;i++)
        {
            mat[i][i]='Y';
            f=0;
            for(j=i+1;j<n;j++)
            {
                if(f==0)
                {
                    if(s2[j-1]=='Y' && s1[j]=='Y')
                    mat[i][j]='Y';
                    else
                    {
                        f=1;
                        mat[i][j]='N';
                    }
                    
                }
                else
                {
                    mat[i][j]='N';
                }
                
            }
            f=0;
            for(j=i-1;j>=0;j--)
            {
                if(f==0)
                {
                    if(s2[j+1]=='Y' && s1[j]=='Y')
                    mat[i][j]='Y';
                    else
                    {
                        f=1;
                        mat[i][j]='N';
                    }
                    
                }
                else
                {
                    mat[i][j]='N';
                }
            }
        }
        cout<<"Case #"<<tt<<":"<<"\n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            cout<<mat[i][j];
            cout<<"\n";
        }
    }
    return 0;
}