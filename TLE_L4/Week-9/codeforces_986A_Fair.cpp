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
#define INF 1e9
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
    
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin); 
    //     freopen("output.txt", "w", stdout); 
    // #endif 
    
    //cout<<"Hello World"<<"\n";
    
    // in this problem, the idea is to run BFS from the goods index, not from each of the nodes
    // this saves from TLE, answer matrix has n rows, indicating towns, and k columns, for the goods
    // we populate this matrix column wise for each k
    // then sort for top s among the k for each row in the matrix, and sum them up for final answer
    ll i,j,k,m,s,n,x,u,v;
    cin>>n>>m>>k>>s;
    unordered_map<ll,vector<ll>>goods;
    for(i=0;i<n;i++){
        cin>>x;
        x--;
        goods[x].pb(i);
    }
    vector<vector<ll>>adj(n);
    for(i=0;i<m;i++){
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vector<ll>>ans(n,vector<ll>(k,0));
    for(i=0;i<k;i++){
        vector<ll>dist(n,INF);
        queue<ll>Q;
        for(auto it:goods[i]){
            Q.push(it);
            dist[it]=0;
        }
        while(!Q.empty()){
            ll town = Q.front();
            Q.pop();
            for(auto v:adj[town]){
                if(dist[town]+1<dist[v]){
                    dist[v]=dist[town]+1;
                    Q.push(v);
                }
            }
        }
        for(j=0;j<n;j++){
            ans[j][i]=dist[j];
        }
    }
    for(i=0;i<n;i++){
        ll sum=0;
        sort(ans[i].begin(),ans[i].end());
        for(j=0;j<s;j++) sum+=ans[i][j];
        cout<<sum<<" ";
    }
    return 0;
}