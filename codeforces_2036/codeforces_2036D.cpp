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

ll solve(const string &layer, const string &pattern) {
    ll count = 0, pos = 0;
    while ((pos = layer.find(pattern, pos)) != string::npos) {
        count++;
        pos++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin); 
    //     freopen("output.txt", "w", stdout); 
    // #endif 
    
    //cout<<"Hello World"<<"\n";
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> carpet(n);
        for (int i = 0; i < n; i++) {
            cin >> carpet[i];
        }

        string pattern = "1543";
        ll total_count = 0;

        for (int layer = 0; layer < min(n, m) / 2; layer++) {
            string layer_seq;

            for (int i = layer; i < m - layer; i++) layer_seq += carpet[layer][i];
            for (int i = layer + 1; i < n - layer; i++) layer_seq += carpet[i][m - layer - 1];
            for (int i = m - layer - 2; i >= layer; i--) layer_seq += carpet[n - layer - 1][i];
            for (int i = n - layer - 2; i > layer; i--) layer_seq += carpet[i][layer];

            string extd_layer_seq = layer_seq + layer_seq.substr(0, 3);

            total_count += solve(extd_layer_seq, pattern);
        }

        cout << total_count << "\n";
    }

    return 0;
}