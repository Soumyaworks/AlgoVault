// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,k;
    string s1,s2;
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(i=0;i<=m;i++)
        dp[i][0]=i;
    for(j=0;j<=n;j++)
        dp[0][j]=j;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s2[i-1]==s1[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    cout<<dp[m][n];
    return 0;
}