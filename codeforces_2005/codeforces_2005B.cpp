#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int tt; cin >> tt;

    while(tt--) {
        int n, m, q; cin >> n >> m >> q;

        vector<int>arr(m);
        for(auto &i : arr) cin >> i;

        sort(arr.begin(), arr.end());

        for(int i = 0; i < q; i++) {
            int x; cin >> x;
            int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            int left = right - 1;

            if(right == m) {
                cout << (n - x) + (x - arr[left]) << "\n";
            }
            else if(left == -1) {
                cout << x - 1 + (arr[right] - x) << "\n";
            }
            else {
                int distL = x - arr[left], distR = arr[right] - x;
                cout << abs(distL - distR) / 2 + min(distR, distL) << "\n";
            }
        }
    }
}