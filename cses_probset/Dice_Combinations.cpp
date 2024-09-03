#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define ll long long int

int main(){
    ll i,j,k,n;
    cin>>n;
    vector<ll>dp(n+1,0);
    // dp[i] = # ways to make a sum of i
    dp[0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=6;j++){
            if(j<=i)
                dp[i]=(dp[i]+dp[i-j])%mod;
        }
    }
    cout<<dp[n];
    return 0;
}