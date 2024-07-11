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

bool canReachEndDP(string &s, int m, int k) {
    int n = s.size();
    vector<bool> dp(n + 2, false); 
    dp[0] = true; 

    for (int i = 0; i <= n; ++i) {
        if (dp[i]) { 
            if (i < n && s[i] == 'L') {
                for (int j = 1; j <= m; ++j) { 
                    if (i + j <= n && (s[i + j] == 'L' || s[i + j] == 'W')) {
                        dp[i + j] = true;
                    }
                }
            } else if (i < n && s[i] == 'W') {
                for (int step = 1; step <= k; ++step) { 
                    if (i + step <= n && (s[i + step] == 'L' || s[i + step] == 'W')) {
                        dp[i + step] = true;
                    }
                }
            }
        }
    }

    return dp[n + 1]; 
}

bool canReachEndBFS(string &s, int m, int k){
    int n = s.size();
    bool ans=false;
    vector<int>v(n+1,0);
    queue<pair<int,int>>Q;
    Q.push({0,0});
    v[0]=1;
    while(!Q.empty()){
        auto x = Q.front();
        Q.pop();
        if(x.first>0 && x.first<=n && s[x.first-1]=='W' && x.second<k){
            if(x.first+1 == n+1){
                ans=true;
                break;
            }
            if((x.first+1)<=n && s[x.first]!='C' && v[x.first+1]==0){
                v[x.first+1]=1;
                Q.push({x.first+1,x.second+1});
            }
        }
        else if(x.first == 0 || (x.first>0 && s[x.first-1]=='L')){
            int p = 1;
            while(p<=m){
                if(x.first+p == n+1){
                    ans=true;
                    break;
                }
                if((x.first+p)<=n && s[x.first+p-1]!='C' && v[x.first+p]==0){
                    v[x.first+p]=1;
                    Q.push({x.first+p,x.second});
                }
                p++;
            }
        }
    }
    return ans;
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
        int n,m,k,i,j;
        cin>>n>>m>>k;
        string s;
        cin>>s;
        if (canReachEndBFS(s, m, k)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}