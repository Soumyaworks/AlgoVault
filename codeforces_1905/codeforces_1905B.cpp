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

// vector<int> bfs(int s,vector<vector<int>>v,int n)
// {
//     int i,j,k,c,p;
//     vector<int>d(n),visited(n,0);
//     queue<int>Q;
//     Q.push(s);
//     visited[s]=1;
//     d[s]=0;
//     while(!Q.empty())
//     {
//         int u=Q.front();
//         Q.pop();
//         for(int x:v[u])
//         {
//             if(visited[x]==0)
//             {
//                 Q.push(x);
//                 d[x]=d[u]+1;
//                 visited[x]=1;
//             }    
//         }
//     }
//     return d;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     // #ifndef ONLINE_JUDGE 
//     //     freopen("input.txt", "r", stdin); 
//     //     freopen("output.txt", "w", stdout); 
//     // #endif 
    
//     //cout<<"Hello World"<<"\n";
//     int t;
//     while(t--){
//         int n,i,j,k,u,v,c;
//         cin>>n;
//         vector<vector<int>>adj(n);
//         for(i=0;i<n-1;i++){
//             cin>>u>>v;
//             --u;
//             --v;
//             adj[u].pb(v);
//             adj[v].pb(u);
//         }
//         vector<int>d1(n),d2(n);
//         d1=bfs(0,adj,n);
//         c=INT_MIN;
//         int s;
//         for(i=0;i<n;i++)
//         {
//             if(d1[i]>c)
//             {
//                 c=d1[i];
//                 s=i;
//             }
//         }
//         int ans=0;
//         d2=bfs(s,adj,n);
//         ans=*max_element(d2.begin(),d2.end());

//     }
//     return 0;
// }

vector<int> bfs(int s, vector<vector<int>>& v, int n, vector<int>& parent) {
    vector<int> d(n), visited(n, 0);
    queue<int> Q;
    Q.push(s);
    visited[s] = 1;
    d[s] = 0;
    parent[s] = -1;  // Set parent of the starting node to -1
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int x : v[u]) {
            if (visited[x] == 0) {
                Q.push(x);
                d[x] = d[u] + 1;
                visited[x] = 1;
                parent[x] = u;  // Store the parent of the current node
            }
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, i, u, v, c;
        cin >> n;
        vector<vector<int>> adj(n);
        for (i = 0; i < n - 1; i++) {
            cin >> u >> v;
            --u;
            --v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int steps = 0;
        for(i=0;i<n;i++){
            if(adj[i].size()==1)
                steps++;
        }
        // while (n > 1) {
        //     vector<int> d1(n), d2(n), parent(n);

        //     // Finding one end of the diameter
        //     d1 = bfs(adj[0][0], adj, n, parent);
        //     c = INT_MIN;
        //     int s;
        //     for (i = 0; i < n; i++) {
        //         if (d1[i] > c) {
        //             c = d1[i];
        //             s = i;
        //         }
        //     }
        //     cout<<"s="<<s<<"\n";
        //     // Finding the other end of the diameter and retrieving the path
        //     parent.clear();
        //     d2 = bfs(s, adj, n, parent);
        //     int ans = *max_element(d2.begin(), d2.end());

        //     int s2;
        //     for (i = 0; i < n; i++) {
        //         if(d2[i]==ans){
        //             s2=i;
        //             break;
        //         }
        //     }
        //     cout<<"s2="<<s2<<"\n";
        //     // Printing the nodes in the diameter path
        //     vector<int> diameterPath;
        //     int cur = s2;
        //     while (cur != s) {
        //         diameterPath.pb(cur);
        //         cur = parent[cur];
        //     }
        //     diameterPath.pb(s);

        //     cout<<"path:"<<"\n";
        //     for(auto it:diameterPath){
        //         cout<<it<<" ";
        //     }
        //     cout<<"\n";

        //     // Find the minimum vertex number in the diameter path
        //     int newVertexNumber = *min_element(diameterPath.begin(), diameterPath.end());

        //     // Create a new graph with a single vertex for the diameter
        //     vector<vector<int>> newAdj(n - diameterPath.size() + 1);
        //     // int newVertex = n - diameterPath.size();
        //     for (i = 0; i < n; i++) {
        //         if (find(diameterPath.begin(), diameterPath.end(), i) == diameterPath.end()) {
        //             for (int x : adj[i]) {
        //                 if (find(diameterPath.begin(), diameterPath.end(), x) != diameterPath.end()) {
        //                     newAdj[newVertexNumber].pb(x);
        //                     newAdj[x].pb(newVertexNumber);
        //                 }
        //                 else{
        //                     newAdj[x].pb(i);
        //                     newAdj[i].pb(x);
        //                 }
        //             }
        //         }
        //     }

        //     // Update variables for the next iteration
        //     adj = newAdj;
        //     n = adj.size();
        //     cout<<"new n="<<n<<"\n";
        //     for(i=0;i<n;i++){
        //         for(auto x:adj[i]){
        //             cout<<x<<" ";
        //         }
        //         cout<<"\n";
        //     }
        //     steps++;
        // }

        cout << (steps+1)/2 << "\n";
    }
    return 0;
}