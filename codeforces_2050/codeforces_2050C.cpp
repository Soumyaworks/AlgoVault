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

vector<int> valid_squares = {0, 1, 4, 9};

void solve() {
    int t;
    cin >> t;

    while (t--) {
        string n;
        cin >> n;

        int initial_sum = 0;
        for (char c : n) {
            initial_sum += (c - '0');
        }
        initial_sum %= 9;

        
        unordered_set<int> reachable;
        reachable.insert(initial_sum);
        
        for (char c : n) {
            int digit = c - '0';
            int squared_digit = digit * digit;

            if (squared_digit >= 10) continue;
            unordered_set<int> new_reachable = reachable;
            for (int sum : reachable) {
                int new_sum = (sum - digit + squared_digit + 9) % 9;
                new_reachable.insert(new_sum);
            }

            reachable = new_reachable;
        }
        if (reachable.count(0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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
    solve();
    return 0;
}