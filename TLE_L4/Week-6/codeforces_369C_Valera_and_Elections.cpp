// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>&adj,  vector<int>&roads, int x, vector<int>&subtree, int parent){
    if(roads[x]==1)
        subtree[x]++;
    for(auto v:adj[x]){
        if(v==parent) continue;
        subtree[x]+=dfs(adj,roads,v,subtree,x);
    }
    return subtree[x];
}

int main(){
    int n,i,j,k,p,x,y;
    cin>>n;
    vector<vector<int>>adj(n);
    vector<int>roads(n,0);
    for(i=0;i<n-1;i++){
        cin>>x>>y>>k;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if(k==2)
            roads[x]=roads[y]=1;
    }
    vector<int>subtree(n,0);
    dfs(adj,roads,0,subtree,-1);
    vector<int>fans;
    for(i=0;i<subtree.size();i++){
        if(subtree[i]==1) fans.push_back(i+1);
    }
    cout<<fans.size()<<"\n";
    for(auto x:fans) cout<<x<<" ";
    return 0;
}