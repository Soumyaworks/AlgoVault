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

void dfs(int u,vector<int>&visited,vector<vector<int>>&adj,int &nodes,int &edges,unordered_set<int>&NationSet,
        bool &colored_comp,vector<int>&in_degree){
            if(visited[u]) return;
            visited[u]=true;
            if(NationSet.count(u)) colored_comp=true;
            for(auto it:adj[u]){
                if(!visited[it])
                    dfs(it,visited,adj,nodes,edges,NationSet,colored_comp,in_degree);
            }
            nodes++;
            edges+=(in_degree[u]);
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
    int n,m,k,i,j,p;
    cin>>n>>m>>k;
    vector<int>nations(k);
    for(auto &x:nations) cin>>x;
    vector<vector<int>>adj(n);
    vector<int>in_degree(n,0);
    for(i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
        in_degree[u]++;
        in_degree[v]++;
    }
    vector<pair<int,int>>colored_components, non_colored_components;
    unordered_set<int>NationSet;
    for(auto it:nations) NationSet.insert(it-1);
    vector<int>visited(n,0);
    for(i=0;i<n;i++){
        if(!visited[i]){
            int nodes = 0;
            int edges = 0;
            bool colored_comp=false;
            dfs(i,visited,adj,nodes,edges,NationSet,colored_comp,in_degree);
            edges/=2;
            if(colored_comp) colored_components.pb({nodes,edges});
            else non_colored_components.pb({nodes,edges});
        }
    }
    int ans=0;
    int mx_nodes=0;
    for(auto it:colored_components){
        mx_nodes = max(mx_nodes,it.first);
        int mx_edges = (it.fi*(it.fi-1))/2;
        ans+=(mx_edges-it.se);
    }
    // cout<<"ans over here:"<<ans<<"\n";
    // cout<<"max nodes in a component:"<<mx_nodes<<"\n";
    int existing_edges = 0, non_colored_nodes = 0;
    for(auto it:non_colored_components){
        // cout<<"non colored comp:"<<it.fi<<","<<it.se<<"\n";
        // int mx_edges = (it.fi*(it.fi-1))/2;
        // ans+=(mx_edges-it.se);
        ans+=(mx_nodes*it.fi);
        existing_edges+=it.se;
        non_colored_nodes+=it.fi;
    }
    int new_component_nodes = (non_colored_nodes*(non_colored_nodes-1))/2;
    new_component_nodes-=existing_edges;
    ans+=new_component_nodes;
    cout<<ans;
    return 0;
}