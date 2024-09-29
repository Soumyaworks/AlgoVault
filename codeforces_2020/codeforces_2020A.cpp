// Author: Soumya Banerjee
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll nearestPowerOfK(ll N, ll K) {
    
    ll lg = log(N) / log(K);
    ll a = pow(K, lg);
    ll b = pow(K, lg + 1);

    
    if ((N - a) < (b - N))
        return lg;
    return lg + 1;
}

ll minOperationsToZero(ll n, ll k) {
    ll operations = 0;
    ll powerValue = 0,p;
    
    while (n > 0) {
        
        // p = nearestPowerOfK(n, k);
        // cout<<"first p ="<<p<<"\n";
        // powerValue = (ll)pow(k, p);
        // cout<<"initial powervlaue: "<<powerValue<<"\n";
        // if (powerValue > n) {
            
        //     p--;
        //     powerValue = (ll)pow(k, p);
        // }

        // n -= powerValue;

        operations+=n%k;  
        n/=k;
        // break;
    }
    // cout<<"powervlaue:"<< powerValue<<", p="<<p<<"\n";
    // operations+= n;
    return operations;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if(k==1 || k>n){
            cout<<n<<"\n";
            continue;
        }
        ll result = minOperationsToZero(n, k);
        cout << result << "\n";
    }
    
    return 0;
}
