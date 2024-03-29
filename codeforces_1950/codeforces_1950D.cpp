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



bool isBinaryDecimal(int num) {
    if (num == 0) { // 0 is a binary digit
        return true;
    }

    while (num > 0) {
        int digit = num % 10;
        if (digit != 0 && digit != 1) {
            return false;
        }
        // Check for potential division by zero
        if (num < 10) { // If num is single-digit, prevent infinite loop
            break;
        }
        num /= 10;
    }
    return true;
}

bool canRepresentAsProduct(int n,unordered_map<int, bool> &dp) {
    if (n == 1){
        dp[n]=true;
        return true;
    }
        // return true;
    
    if (dp.find(n) != dp.end())
        return dp[n];
    
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            int factor1 = i;
            int factor2 = n / i;
            if ((isBinaryDecimal(factor1) || canRepresentAsProduct(factor1,dp)) &&
                (isBinaryDecimal(factor2) || canRepresentAsProduct(factor2,dp))) {
                dp[n] = true;
                return true;
            }
        }
    }
    dp[n] = false;
    return false;
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
        int n;
        cin >> n;
        unordered_map<int, bool> dp;
        dp[1]=true;
        if (isBinaryDecimal(n) ||  canRepresentAsProduct(n,dp))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}