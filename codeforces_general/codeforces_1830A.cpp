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

vector<int>dp(2e5),ind(2e5);
vector<vector<pair<int,int>>>edge(2e5);

// dp[v]=dp[u]+1, when index(u,v)<=ind(u), meaning we need to look back, re-traverse

void dfs(int u){
    for(auto it : edge[u]){
        if(dp[it.first] == 0){
            dp[it.first] = dp[u] + (it.second <= ind[u]);
            ind[it.first] = it.second;
            dfs(it.first);
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
    int t;
    cin>>t;
    while(t--){
        int n,i,j,k;
        cin>>n;
        // vector<int>dp(2e5),ind(2e5);
        // vector<vector<pair<int,int>>>edge(2e5);
        for(int i=1; i<=n; i++) dp[i] = ind[i] = 0, edge[i].clear();
        for(i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            edge[u].pb({v,i});
            edge[v].pb({u,i});
            // dp[i]=0;
            // ind[i]=0;
        }
        // dp[n]=ind[n]=0;
        dp[1]=1;
        dfs(1);
        // cout<<*max(dp.begin(),dp.begin()+n-1)<<"\n";
        int ans=0;
        for(i=1;i<=n;i++)
            ans=max(ans,dp[i]);
        cout<<ans<<"\n";
    }
    return 0;
}
