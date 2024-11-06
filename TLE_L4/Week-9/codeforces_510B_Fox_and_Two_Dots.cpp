// Author : Soumya Banerjee
// "Great things are not done by impulse, but by a series of small things brought together." - Vincent Van Gogh
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#define ll long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define mod 1000000007
#define fill(a, x) memset(a, x, sizeof(a))
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

struct node {
    int x, y;
};

// Check if the given cell (x, y) is the parent of the current cell
bool isParent(node N, int x, int y) {
    return N.x == x && N.y == y;
}

bool isCycle(vector<string>& grid, int i, int j, vector<vector<char>>& visited) {
    int n = grid.size(), m = grid[0].size();
    node src = {i, j};
    node prev = {-1, -1};  // Previous node in the BFS
    queue<pair<node, node>> Q;
    visited[i][j] = '1';
    Q.push({src, prev});
    
    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        
        int x = p.first.x;
        int y = p.first.y;
        
        // Possible moves (up, down, left, right)
        vector<pair<int, int>> moves = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
        
        for (auto move : moves) {
            int nx = move.first, ny = move.second;
            
            // Check boundaries and ensure the next cell has the same color
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == grid[x][y]) {
                if (visited[nx][ny] == '1' && !isParent(p.second, nx, ny)) {
                    return true;  // Cycle found
                }
                if (visited[nx][ny] == '0') {
                    visited[nx][ny] = '1';
                    node tgt = {nx, ny};
                    Q.push({tgt, p.first});
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    bool cycle_found = false;
    vector<vector<char>> visited(n, vector<char>(m, '0'));  // Initialize visited with '0' (unvisited)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == '0') {
                cycle_found = isCycle(grid, i, j, visited);
                if (cycle_found) break;
            }
        }
        if (cycle_found) break;
    }

    cout << (cycle_found ? "Yes" : "No") << "\n";
    return 0;
}
