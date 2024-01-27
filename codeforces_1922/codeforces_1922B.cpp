#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,i,j,k;
        cin>>n;
        vector<ll>a(n);
        vector<ll>c(n+1);
        for(i=0;i<n;i++){
            cin>>a[i];
            c[a[i]]++;
        }
        ll ans=0;
        ll smaller=0;
        for(i=0;i<=n;i++){
            ans+=(c[i]*(c[i]-1)*(c[i]-2))/6;
            ans+=(c[i]*(c[i]-1))/2 * smaller;
            smaller+=c[i];
        }   
        cout<<ans<<"\n";
    }

    return 0;
}