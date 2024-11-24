// Author : Soumya Banerjee
// "Great things are not done by impulse, but by a series of small things brought together." - Vincent Van Gogh
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll n, m, l;
        cin >> n >> m >> l;

        vector<pair<ll, ll>> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i].fi >> h[i].se;
        }

        vector<pair<ll, ll>> p(m);
        for (int i = 0; i < m; ++i) {
            cin >> p[i].fi >> p[i].se;
        }

        priority_queue<ll> pq;
        ll jp = 1, ans = 0, idx = 0;

        for (auto& hr : h) {
            ll st = hr.fi, en = hr.se, req = en + 2 - st;

            while (idx < m && p[idx].fi < st) {
                pq.push(p[idx].se);
                idx++;
            }

            while (!pq.empty() && jp < req) {
                jp += pq.top();
                pq.pop();
                ans++;
            }

            if (jp < req) {
                ans = -1;
                break;
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}
