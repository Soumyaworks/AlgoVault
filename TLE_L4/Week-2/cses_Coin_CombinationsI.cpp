// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // this is a bit different problem, than the normal count #ways problem for coin change,
    // in the sense that 2,5,5 and 5,5,2 are considered as different combos contributinng to 2 different ways
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &c : coins) cin >> c;

    vector<int> dp(x + 1, 0);
    dp[0] = 1;  // There's one way to make sum 0, which is using no coins.

    for (int j = 1; j <= x; j++) {
        for (int i = 0; i < n; i++) {
            if (coins[i] <= j) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
            }
        }
    }

    cout << dp[x] % mod;
    return 0;
}
