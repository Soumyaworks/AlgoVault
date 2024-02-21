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

bool dfs(int v,vector<int>&color, vector<int>&parent, vector<set<int>>&adj,int &cycle_start, int &cycle_end) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u,color, parent, adj, cycle_start, cycle_end))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
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
    cin>>t;
    while(t--){
        int i,j,k,n,p;
        cin>>n>>k;
        vector<set<int>>adj(n);
        for(i=1;i<=k;i++){
            int prev;
            cin>>prev;
            prev--;
            for(j=1;j<n;j++){
                cin>>p;
                p--;
                if(j>=2)
                    adj[prev].insert(p);
                prev=p;
            }
        }
        // cout<<"printing the graph : "<<"\n";
        // for(i=0;i<n;i++){
        //     cout<<i<<": ";
        //     for(auto itr:adj[i]){
        //         cout<<itr<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<int>color(n,0),parent(n,-1);
        int cycle_start=-1,cycle_end;
        for(i=0;i<n;i++){
            if(color[i]==0 && dfs(i,color,parent,adj,cycle_start,cycle_end)){
                break;
            }
        }
        if(cycle_start==-1)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";

    }
    return 0;
}