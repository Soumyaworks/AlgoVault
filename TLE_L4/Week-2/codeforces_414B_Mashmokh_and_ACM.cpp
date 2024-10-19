// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int solve(int n, int k, int i, vector<vector<int>>&dp){
    if(k<=0) return 1;
    if(dp[k][i]!=-1) return dp[k][i];
    int ans=0;
    for(int j=i;j<=n;j+=i){
        if(j%i==0){
            ans+=solve(n,k-1,j,dp)%mod;
            ans=ans%mod;
        }
    }
    dp[k][i]=ans;
    return dp[k][i];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,i,j;
    cin>>n>>k;
    vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
    cout<<solve(n,k,1,dp)<<"\n";
    return 0;
}