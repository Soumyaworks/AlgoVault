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
    /*
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    */
    //cout<<"Hello World"<<"\n";
    ll h,n,s,i,j,k,c,p,f;
    cin>>n>>s;
    ll e[n];
    for(i=0;i<n;i++)
    cin>>e[i];
    c=0;k=1;h=0;
    while(k<=n){
    for(i=0;i<n-k+1;i++)
    {
        c=0;
        for(j=i;j<i+k;j++)
        c+=e[j]+((j+1)*k);
        if(c<=s && c>h)
        {
            h=c;
            f=k;
        }

    }
    k++;
    }
    cout<<f<<"\n";
    return 0;
}