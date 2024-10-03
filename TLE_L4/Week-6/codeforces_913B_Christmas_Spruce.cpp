// Author : Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,n;
    cin>>n;
    vector<int>children(n+2,0);
    vector<vector<int>>adj(n+2);
    for(i=2;i<=n;i++){
        cin>>k;
        children[k]++;
        adj[k].push_back(i);
    }
    // for(auto x:children) cout<<x<<",";
    // cout<<"\n";
    int flag = 0;
    for(i=1;i<=n;i++){
        int count=0;
        for(auto x:adj[i]){
            if(children[x]==0)
                count++;
        }
        if(!adj[i].empty() && count<3) {flag=1;break;}
    }
    if(flag==1) cout<<"No";
    else cout<<"Yes";
    return 0;
}