// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&child, int v, string &s, int &ans){
    int bal=0;
    bal=(s[v-1]=='B')?-1:1;
    if(child[v].empty()) return bal;
    for(auto c:child[v])
        bal+=solve(child,c,s,ans);
    if(bal==0) ans++;
    return bal;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,i,j,k;
        cin>>n;
        vector<vector<int>>child(n+1);
        for(i=2;i<=n;i++){
            int x;
            cin>>x;
            child[x].push_back(i);
        }
        string s;
        cin>>s;
        int ans=0;
        solve(child,1,s,ans);
        cout<<ans<<"\n";
    }
}