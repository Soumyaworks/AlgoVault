#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("Ofast")
#define ll int
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

//sparse table 
ll maxn;
void precompute(vector<ll>&loga,ll n)
{
    //maxn=n;
    loga[1] = 0;
    ll i,j,k;
    for (i = 2; i <=n; i++)
        loga[i] = loga[i/2] + 1;  

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello World"<<"\n";
    ll m,n,i,j,k,p;
    cin>>n;
    vector<ll>a(n);
    vector<ll>loga(n+1);
    k=floor(log2(n));
    ll st[n][k+1];
    precompute(loga,n);
    for(i=0;i<n;i++)
    {
        //cin>>a[i];
        cin>>st[i][0];
    }
    ll x1,y1,x,y;
    cin>>m>>x1>>y1;
    
    //SegmentTree ob(a);
    //for (i = 0; i < n; i++)
      //  st[i][0] = a[i];

    for (j = 1; j <= k; j++)
        for (i = 0; i + (1 << j) <= n; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

    
    long long int c=0;
    for(i=1;i<=m;i++)
    {
        if(i==1)
        {
            x1=x1;
            y1=y1;
        }
        else
        {
            x1=(x1+7)%(n-1);
            y1=(y1+11)%n;
        }
        x=min(x1,y1);
        y=max(x1,y1);
        //cout<<ob.rmq(x,y)<<"\n";
        //c+=a[ob.rmq(x,y)];
        j=log2(y-x+1);
        c+=max(st[x][j], st[y - (1 << j) + 1][j]);
        //c+=p;
    }
    cout<<c<<"\n";
    return 0;
}