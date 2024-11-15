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

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int root_u = findUPar(u);
        int root_v = findUPar(v);
        if (root_u == root_v) return;
        if (size[root_u] < size[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        } else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> passwords(n);
    for (int i = 0; i < n; i++) {
        cin >> passwords[i];
    }

    DisjointSet ds(n);
    unordered_map<char, int> charMap;

    for (int i = 0; i < n; i++) {
        for (char ch : passwords[i]) {
            if (charMap.find(ch) != charMap.end()) {
                ds.unionBySize(i, charMap[ch]);
            } else {
                charMap[ch] = i;
            }
        }
    }

    set<int> uniqueComponents;
    for (int i = 0; i < n; i++) {
        uniqueComponents.insert(ds.findUPar(i));
    }

    cout << uniqueComponents.size() << endl;
    return 0;
}
