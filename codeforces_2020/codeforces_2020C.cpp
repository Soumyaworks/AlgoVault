#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
    ll b, c, d;
    cin >> b >> c >> d;

    ll a = 0; // Initialize a
    bool possible = true; // Track if a solution is possible

    // We will analyze bits from 0 to 60 (sufficient for 0 ≤ b, c, d ≤ 10^18)
    for (int i = 0; i < 60; i++) {
        ll bit_b = (b >> i) & 1;
        ll bit_c = (c >> i) & 1;
        ll bit_d = (d >> i) & 1;

        // If we need d's bit to be 1
        if (bit_d == 1) {
            // If c's bit is 0, we must set it in a since we can't get it from b
            if (bit_c == 0) {
                // We need to set this bit in a since b does not have it
                a |= (1LL << i);
            }
        } else { // bit_d is 0
            // If both b and c have this bit set, it's impossible to achieve d being 0
            if (bit_b == 1 && bit_c == 1) {
                possible = false;
                break;
            }
        }
    }

    cout << (possible ? a : -1) << "\n"; // Output the found value of a or -1
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
