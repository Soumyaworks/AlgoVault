// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj, vector<int>&a, int &m, int &ans, int src, vector<bool>&visited, int count){
    if(visited[src]) return;
    visited[src]=true;
    if(a[src]) count++;
    else count=0;
    if(count>m) {count--;return;}
    // if(adj[src].size()==1){
    //     ans++;
    //     return;
    // }
    bool leaf=true;
    for(auto x:adj[src]){
        if(!visited[x]){
            leaf=false;
            dfs(adj,a,m,ans,x,visited,count);
        }
    }

    if(leaf) ans++;
    // if(a[src]) count--;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,k,x,y;
    cin>>n>>m;
    vector<int>a(n);
    vector<bool>visited(n,false);
    for(auto &x:a) cin>>x;
    vector<vector<int>>adj(n);
    for(i=0;i<n-1;i++){
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans=0;
    dfs(adj,a,m,ans,0,visited,0);
    cout<<ans;
    return 0;
}