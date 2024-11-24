#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<map<int, int>> dp(n); // dp[i][g] stores count of paths ending at i with GCD g
    dp[0][a[0]] = 1;             // Start with the first city

    for (int i = 1; i < n; i++) {
        // Carry forward all previous GCD states
        for (auto &[g, count] : dp[i - 1]) {
            int new_gcd = gcd(g, a[i]);
            dp[i][new_gcd] = (dp[i][new_gcd] + count) % MOD;
        }
        // Start a new path with city i itself
        dp[i][a[i]] = (dp[i][a[i]] + 1) % MOD;
    }

    // Sum all paths ending at city n-1 with GCD > 1
    int result = 0;
    for (auto &[g, count] : dp[n - 1]) {
        if (g > 1) {
            result = (result + count) % MOD;
        }
    }

    cout << result << "\n";
    return 0;
}
