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

void dfs_visit(vector<vector<int>>&adj,int u,int v,vector<bool>&visited,vector<int>&a,vector<int>&p,vector<int>&b,int i,vector<int>&mark)
{
    visited[u]=true;
    //static int time=1;
    //cout<<"visited city="<<u<<"\n";
    if(mark[u]!=1){
        //cout<<"b[u]="<<b[u]<<" a[v]="<<a[v]<<"\n";
    //b[u]-=min(a[v],b[u]);
    if(a[v]<=b[u])
    b[u]=b[u]-a[v];
    else
    {
        b[u]=0;
    }
    
    
    if(b[u]==0)
    {
        b[u]=i+1;
        mark[u]=1;
    }
    }
    //cout<<"changed b[u]="<<b[u]<<"\n";
    //time++;
    for(auto x:adj[u])
    {
        if(!visited[x])
        dfs_visit(adj,x,v,visited,a,p,b,i,mark);
        
        
    }
}
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
    int n,t,u,v,i,j,k,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<vector<int>>adj(n);
        for(i=0;i<n-1;i++)
        {
            cin>>u;
            cin>>v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int>p(n),a(n),b(n),mark(n,0);
        for(i=0;i<n;i++)
        {
            cin>>p[i];
            --p[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
        }
        vector<bool>visited(n,false);
        for(i=0;i<n;i++)
        {
            if(!visited[p[i]])
            {
                dfs_visit(adj,p[i],p[i],visited,a,p,b,i,mark);
                adj[p[i]].clear();
                for(j=0;j<n;j++)
                {
                    for(k=0;k<adj[j].size();k++)
                    {
                        if(adj[j][k]==p[i])
                        adj[j].erase(adj[j].begin()+k);
                    }
                }
                /*
                cout<<"adjacency list:\n";
                for(j=0;j<n;j++)
                {
                    for(auto it:adj[i])
                    {
                        cout<<it<<" ";
                    }
                    cout<<"\n";
                }
                */
                for(j=0;j<n;j++)
                visited[j]=false;
                for(j=0;j<=i;j++)
                visited[p[j]]=true;
                //a[p[i]]=-1;
            }
            
        }
        for(i=0;i<n;i++)
        {
            if(mark[i]==1)
            cout<<b[i]<<" ";
            else
            {
                cout<<-1<<" ";
            }
            
        }
        cout<<"\n";


    }
    return 0;
}