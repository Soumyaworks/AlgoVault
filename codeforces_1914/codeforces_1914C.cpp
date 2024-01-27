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
long long maxExperience(int n, int k,vector<int>& a, vector<int>& b) {
    vector<long long> dp(n + 1, LLONG_MIN);
    dp[1] = a[0];

    for (int i = 2; i <= n; ++i) {
        for (int j = i - 1; j >= max(1, i - k); --j) {
            dp[i] = max(dp[i], dp[j] + (long long)(i - j - 1) * b[i - 1] + a[i - 1]);
        }
    }

    long long result = LLONG_MIN;
    for (int i = max(1, n - k + 1); i <= n; ++i) {
        result = max(result, dp[i]);
    }

    return result;
}

int max_experience(std::vector<int>& a,std::vector<int>& b, int n, int k) {
  // dp[i][j] stores the maximum experience Monocarp can get with j quests completed, ending with the i-th quest.
//   std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

//   // The first quest is always available.
//   dp[1][1] = a[1];

//   for (int i = 2; i <= n; ++i) {
//     // Consider completing the i-th quest for the first time (with j quests completed).
//     for (int j = 1; j <= k; ++j) {
//       dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + a[i]);
//     }

//     // Consider completing quests before the i-th quest (with j quests completed).
//     for (int j = k; j >= 1; --j) {
//       dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
//     }

//     // Consider completing the i-th quest at least once (with j quests completed).
//     for (int j = 1; j <= k; ++j) {
//       dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + b[i]);
//     }
//   }

//   // Return the maximum total experience.
//   return *std::max_element(dp[n].begin(), dp[n].end());
    // vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    // for (int i = 1; i <= n; ++i) {
    //         for (int j = 1; j <= k; ++j) {
    //             // Calculate experience points for completing the i-th quest once
    //             dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i - 1]);

    //             // Calculate experience points for completing the i-th quest multiple times
    //             for (int x = 1; x <= j; ++x) {
    //                 dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + x * b[i - 1]);
    //             }
    //         }
    //     }

    //     // Find the maximum experience points Monocarp can get by completing at most k quests
    //     int maxExp = 0;
    //     for (int j = 1; j <= k; ++j) {
    //         maxExp = max(maxExp, dp[n][j]);
    //     }

    // return maxExp;

    // vector<int> dp(n + 1, 0);

    // for (int i = 1; i <= n; ++i) {
    //     dp[i] = dp[i - 1] + a[i - 1];

    //     for (int j = 1; j <= min(i, k); ++j) {
    //         dp[i] = max(dp[i], dp[i - j] + b[i - 1] * (j - 1) + a[i - 1]);
    //     }
    // }

    // return dp[n];
//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

//   // Base cases:
//   dp[1][1] = a[0];  // First quest, must be completed once

//   for (int i = 2; i <= n; ++i) {
//     // Complete the i-th quest for the first time
//     dp[i][1] = a[i - 1] + max(dp[i - 1][1], dp[i - 1][0]);

//     // Complete the i-th quest multiple times (iterate backwards)
//     for (int j = k; j >= 2; --j) {  // Start from j = 2, not j = 1
//       // Consider options with and without the current quest
//       int with_i = max(dp[i - 1][j - 1] + a[i - 1], dp[i][j - 2] + b[i - 1]); // Use dp[i][j-2] here
//       int without_i = dp[i - 1][j];

//       // Choose the best option based on remaining quests
//       dp[i][j] = max(with_i, without_i);
//     }
//   }

//   return *max_element(dp[n].begin(), dp[n].end());

    //  vector<vector<int>> dp(n + 1, vector<int>(k + 2, 0)); // Change size of dp table

    // // Base cases:
    // dp[1][1] = a[0]; // First quest, must be completed once
    // dp[1][2] = max(a[0] + b[0], 0); // Optional second completion for the first quest

    // for (int i = 2; i <= n; ++i) {
    //     // Complete the i-th quest for the first time
    //     dp[i][1] = a[i - 1] + max(dp[i - 1][1], dp[i - 1][0]);

    //     // Complete the i-th quest multiple times (iterate backwards)
    //     for (int j = k + 1; j >= 2; --j) {
    //         // Consider options with and without the current quest
    //         int with_i = max(dp[i - 1][j - 1] + a[i - 1], dp[i][j - 2] + b[i - 1]); // Use dp[i][j-2]
    //         int without_i = dp[i - 1][j];

    //         // Choose the best option based on remaining quests
    //         dp[i][j] = max(with_i, without_i);
    //     }
    // }

    // return dp[n][k + 1]; 
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        // Calculate experience points for completing the i-th quest for the first time
        dp[i] = max(dp[i], dp[i - 1] + a[i - 1]);

        // Calculate experience points for completing the i-th quest multiple times
        for (int j = 1; j <= min(i, k); ++j) {
            dp[i] = max(dp[i], dp[i - j] + b[i - 1] * (j - 1) + a[i - 1]);
        }
    }

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
        int n,k,i,j,ans=0;
        cin>>n>>k;
        vector<int>a(n),b(n);
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        for(i=0;i<n;i++){
            cin>>b[i];
        }
        // cout<<maxExperience(n,k,a,b)<<"\n";
        // cout<<max_experience(a,b,n,k)<<"\n";
        // int ans=0;
        int mx=0,sum=0;
        for(i=0;i<min(n,k);i++){
            sum+=a[i];
            mx=max(mx,b[i]);
            j=sum+(k-i-1)*mx;
            ans=max(ans,j);
        }
        cout<<ans<<"\n";
    }
    return 0;
}