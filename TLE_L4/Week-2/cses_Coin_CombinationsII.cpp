// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,i,j,k;
    cin>>n>>x;
    vector<int>coins(n);
    for(i=0;i<n;i++) cin>>coins[i];
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(i=0;i<=n;i++)
        dp[i][0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=x;j++){
            if(coins[i-1]<=j){
                dp[i][j]=(dp[i][j-coins[i-1]] + dp[i-1][j])%mod;
            }
            else
                dp[i][j]=dp[i-1][j]%mod;
        }
    }
    cout<<dp[n][x];
    return 0;
}