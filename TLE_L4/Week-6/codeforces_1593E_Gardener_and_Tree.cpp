// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--; v--; // zero-indexed
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        // Special case handling
        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
        
        vector<int> leaves;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){  // leaf node
                leaves.push_back(i);
            }
        }
        
        int total_removed = 0;
        while(k-- && !leaves.empty()){
            vector<int> new_leaves;
            for(auto leaf : leaves){
                total_removed++;
                for(auto neighbor : adj[leaf]){
                    degree[neighbor]--;
                    if(degree[neighbor] == 1){
                        new_leaves.push_back(neighbor);
                    }
                }
            }
            leaves = new_leaves;
        }
        
        int remaining_vertices = max(0, n - total_removed);
        cout << remaining_vertices << "\n";
    }
    
    return 0;
}
