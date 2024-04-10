//Author : Soumya Banerjee
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


// int minCost(int n, int a, int b) {
//     if (n <= 0)
//         return 0;
//     if (n == 1)
//         return a;
//     if (n % 2 == 0)
//         return min(n / 2 * b, n * a);
//     else
//         return min(n / 2 * b + a, (n / 2) * b + minCost(n / 2 + 1, a, b));
// }

// int minCost(int n, int a, int b) {
//     if (n <= 0)
//         return 0;
//     if (n == 1)
//         return a;
//     int min_cost = INT_MAX;
//     for (int i = 0; i <= n; ++i) {
//         int cost = i * b + max(0, (n - 2 * i)) * a;
//         min_cost = min(min_cost, cost);
//     }
//     return min_cost;
// }

// int minCost(int n, int a, int b) {
//     // Base cases:
//     if (n == 0) {
//         return 0;
//     } else if (n == 1) {
//         return a;
//     }

   
//     int option1 = minCost(n - 1, a, b) + a;  // Buy 1 yogurt
//     int option2 = minCost(n - 2, a, b) + b;  // Buy 2 yogurts

//     return min(option1, option2);
// }

int minCost(int n, int a, int b, unordered_map<int, int>& dp) {
    // Base cases:
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return a;
    }

    if (dp.count(n) > 0) {
        return dp[n];
    }

    int option1 = minCost(n - 1, a, b, dp) + a;  // Buy 1 yogurt
    int option2 = minCost(n - 2, a, b, dp) + b;  // Buy 2 yogurts

    
    dp[n] = min(option1, option2);

    
    return dp[n];
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
    cin>>t;
    while(t--){
        int i,j,k,a,b,n;
        cin>>n>>a>>b;
        unordered_map<int,int>dp;
        cout<<minCost(n,a,b,dp)<<"\n";
    }
    
    return 0;
}