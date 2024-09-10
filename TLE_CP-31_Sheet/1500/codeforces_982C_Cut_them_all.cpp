// Author : Soumya Banerjee
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")

#define ll long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define mod 1000000007
#define fill(a,x) memset(a,x,sizeof(a))
#define indexed_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
using namespace __gnu_pbds;

vector<ll> vec[112345];
ll dp[112345];

void dfs(ll node, ll parent) {
    for (auto x : vec[node]) {
        if (x != parent) {
            dfs(x, node);
            dp[node] += dp[x];
        }
    }
    dp[node]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll node, edge;
    cin >> node;
    edge = node - 1;
    for (ll i = 0; i < edge; i++) {
        ll x, y;
        cin >> x >> y;
        vec[x].pb(y);
        vec[y].pb(x);
    }

    ll leaf = 0;
    for (ll i = 1; i <= node; i++) {
        if (vec[i].size() == 1) {
            leaf = i;
            break;
        }
    }

    dfs(leaf, -1);

    ll ans = 0;
    for (ll i = 1; i <= node; i++) {
        if (!(dp[i] & 1) && vec[i].size() != 1) {
            ans++;
        }
    }

    if (node % 2 == 0)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}
