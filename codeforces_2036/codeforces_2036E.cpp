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
#define indexed_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
using namespace __gnu_pbds;

// Defllion for a Linked List
struct ListNode {
    ll val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(ll x) : val(x), next(nullptr) {}
    ListNode(ll x, ListNode *next) : val(x), next(next) {}
    //ListNode *head=new ListNode();
    //ListNode *ptr1,*ptr2;
};

// Definition for a binary tree node.
struct TreeNode {
    ll val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    //TreeNode *root=new TreeNode();
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin); 
    //     freopen("output.txt", "w", stdout); 
    // #endif 
    
    //cout<<"Hello World"<<"\n";
    ll n, k, q;
    cin >> n >> k >> q;

    vector<vector<ll>> water_levels(n, vector<ll>(k, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < k; j++) {
            ll water_value;
            cin >> water_value;
            water_value |= (i > 0 ? water_levels[i - 1][j] : 0);
            water_levels[i][j] = water_value;
        }
    }

    while (q--) {
        ll m;
        cin >> m;
        vector<pair<ll, ll>> less, greater;

        for (ll idx = 0; idx < m; idx++) {
            char op;
            ll reg_index, value_limit;
            cin >> reg_index >> op >> value_limit;

            reg_index--; 
            if (op == '<') {
                less.push_back({reg_index, value_limit});
            } else {
                greater.push_back({reg_index, value_limit});
            }
        }

        ll min_country = 0;
        for (auto x : greater) {
            ll region = x.first;
            ll limit = x.second;
            ll left = 0, right = n - 1, first_country = n;
            while (left <= right) {
                ll mid = left + (right - left) / 2;
                if (water_levels[mid][region] > limit) {
                    first_country = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            min_country = max(min_country, first_country);
        }

        if (min_country >= n) {
            cout << -1 << "\n";
        } else {
            bool valid = true;
            for (auto x : less) {
                ll region = x.first;
                ll limit = x.second;
                if (water_levels[min_country][region] >= limit) {
                    valid = false;
                    break;
                }
            }
            if(valid) cout<<(min_country+1)<<"\n";
            else cout<<-1<<"\n";
        }
    }
    return 0;
}