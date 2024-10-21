// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,i,j,k,p;
    cin>>n>>x;
    vector<int>coins(n);
    for(auto &c:coins) cin>>c;
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    // base case, in this problem, also need to fill 1st row, to check if only one element, does that yield sum
    for(j=0;j<=x;j++){
        dp[0][j]=INF;
        dp[1][j]=(j%coins[0]==0)?j/coins[0]:INF;
    }
    for(i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(i=2;i<=n;i++){
        for(j=1;j<=x;j++){
            if(coins[i-1]<=j){
                dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    int ans = (dp[n][x]==INF)?-1:dp[n][x];
    cout<<ans;
}