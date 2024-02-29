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


// int minPathSum(vector<vector<int>>grid, vector<vector<int>>&a) {
//         //int c=grid[0][0];
//         int n=grid[0].size();
//         int m=grid.size();
//         // int a[m][n];
//         a[0][0]=grid[0][0];
//         for(int i=1;i<m;i++)
//             a[i][0]=a[i-1][0]+grid[i][0];
        
//         for(int j=1;j<n;j++)
//             a[0][j]=a[0][j-1]+grid[0][j];
        
//         for(int i=1;i<m;i++)
//         {
//             for(int j=1;j<n;j++)
//                 a[i][j]=min(a[i-1][j],a[i][j-1])+grid[i][j];
//         }
//         return a[m-1][n-1];
// }

int minPathSum(vector<vector<int>> grid, vector<vector<int>>& a) {
    int n = grid[0].size();
    int m = grid.size();
    a[0][0] = grid[0][0];
    for (int i = 1; i < m; i++)
        a[i][0] = a[i - 1][0] + grid[i][0];
    
    for (int j = 1; j < n; j++)
        a[0][j] = a[0][j - 1] + grid[0][j];
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++)
            a[i][j] = min(a[i - 1][j], a[i][j - 1]) + grid[i][j];
    }
    return a[m - 1][n - 1];
}

void findPaths(vector<vector<int>> grid, int i, int j, string path, vector<string>& paths,vector<vector<int>>&a,int c) {
    int m = grid.size();
    int n = grid[0].size();

    if (i == m - 1 && j == n - 1) {
        // paths.push_back(path);
        paths.push_back(path + to_string(grid[i][j]));
        return;
    }

    if (i < m - 1 && grid[i + 1][j] == minPathSum(grid,a) - a[i][j]) {
        findPaths(grid, i + 1, j, path + to_string(grid[i][j]), paths,a,c);
    }

    if (j < n - 1 && grid[i][j + 1] == minPathSum(grid,a) - a[i][j]) {
        findPaths(grid, i, j + 1, path + to_string(grid[i][j]), paths,a,c);
    }
}

// vector<string> getPaths(vector<vector<int>> grid, vector<vector<int>>&a) {
//     vector<string> paths;
//     findPaths(grid, 0, 0, "", paths,a);
//     return paths;
// }



// void findPaths(vector<vector<int>> grid, int i, int j, string path, vector<string>& paths, vector<vector<int>>& a, int minSum) {
//     int m = grid.size();
//     int n = grid[0].size();

//     if (i == m - 1 && j == n - 1) {
//         cout<<"path : "<<path <<"\n";
//         paths.push_back(path + to_string(grid[i][j])); // Include the last element of the path
//         return;
//     }

//     if (i < m - 1 && a[i + 1][j] + grid[i][j] == a[i][j]) {
//         findPaths(grid, i + 1, j, path + "D", paths, a, minSum);
//     }

//     if (j < n - 1 && a[i][j + 1] + grid[i][j] == a[i][j]) {
//         findPaths(grid, i, j + 1, path + "R", paths, a, minSum);
//     }
// }

// void findPaths(vector<vector<int>> grid, int i, int j, string path, vector<string>& paths, vector<vector<int>>& a, int minSum) {
//     int m = grid.size();
//     int n = grid[0].size();

//     if (i == m - 1 && j == n - 1) {
//         paths.push_back(path + to_string(grid[i][j])); // Include the last element of the path
//         return;
//     }

//     if (i < m - 1 && a[i + 1][j] + grid[i][j] == a[i][j]) {
//         cout<<"element : "<< (char)grid[i][j]<<" ";
//         findPaths(grid, i + 1, j, path + ((char)grid[i][j]), paths, a, minSum);
//     }

//     if (j < n - 1 && a[i][j + 1] + grid[i][j] == a[i][j]) {
//         findPaths(grid, i, j + 1, path + ((char)grid[i][j]), paths, a, minSum);
//     }
// }

vector<string> getPaths(vector<vector<int>>grid, vector<vector<int>>& a, int minSum) {
    vector<string> paths;
    findPaths(grid, 0, 0, "", paths, a, minSum);
    return paths;
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
        string s1,s2;
        cin>>s1;
        cin>>s2;
        vector<vector<int>>matrix(2,vector<int>(n)),a(2,vector<int>(n));
        for(i=0;i<2;i++){
            for(j=0;j<n;j++){
                if(i==0)
                matrix[i][j]=s1[j]-'0';
                else
                matrix[i][j]=s2[j]-'0';
            }
        }
        int cost=minPathSum(matrix,a);
        // cout<<cost<<"\n";
        vector<string> paths = getPaths(matrix,a,cost);
        // cout << "Paths with minimum cost:" << endl;
        // for (string path : paths) {
        //     cout << path << endl;
        // }
        sort(paths.begin(),paths.end());
        cout<<paths[0]<<"\n";

    }
    return 0;
}