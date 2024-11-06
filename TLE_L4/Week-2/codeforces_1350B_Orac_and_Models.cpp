// Author: Soumya Banerjee
// "Great things are not done by impulse, but by a series of small things brought together." - Vincent Van Gogh
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    ll n,i,j,k;
    cin>>n;
    vector<ll>a(n);
    for(auto &x:a) cin>>x;
    vector<ll>dp(n+1,1);
    ll ans=0;
    for(i=1;i<=n;i++){
        for(j=2*i;j<=n;j+=i){
            if(a[i-1]<a[j-1])
                dp[j]=max(dp[j],dp[i]+1);
        }
    }
    ans=*max_element(dp.begin(),dp.end());
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}