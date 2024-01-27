//Author : Soumya Banerjee
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("Ofast")
#define ll long long int
#define pb push_back
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define mod 1000000007
#define fill(a,x) memset(a,x,sizeof(a))
#define indexed_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
using namespace __gnu_pbds;

// Defintion for a Linked List
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    //ListNode *head=new ListNode();
    //ListNode *ptr1,*ptr2;
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    //TreeNode *root=new TreeNode();
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> u(n), s(n);

        // Read u and s values in a single loop
        for (ll i = 0; i < n; i++) {
            cin >> u[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> s[i];
        }

        unordered_map<ll, vector<ll>> m;
        for (ll i = 0; i < n; i++) {
            m[u[i]].push_back(s[i]);
        }

        for (auto& it : m) {
            sort(it.second.rbegin(), it.second.rend());

            // Calculate cumulative sums in a more optimized way
            for (ll j = 1; j < it.second.size(); j++) {
                it.second[j] += it.second[j - 1];
            }
        }

        ll f = 0;
        vector<ll> ans(n, 0);

        // Iterate over the map only once and calculate the answer
        for (auto& it : m) {
            ll size = it.second.size();

            for (ll k = 1; k <= size; k++) {
                ll i = (size / k) * k - 1;
                ll j = (i >= 0) ? it.second[i] : 0;
                ans[k - 1] += j;
            }
        }

        for (ll k = 1; k <= n; k++) {
            if (f == 1) {
                cout << 0 << " ";
            } else {
                cout << ans[k - 1] << " ";
                if (ans[k - 1] == 0) {
                    f = 1;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}