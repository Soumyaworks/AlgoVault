#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("Ofast")
#define ll long long int
#define pb push_back
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

vector<pair<int,int>>directions={{-1,0},{0,-1},{0,1},{1,0}};
bool check(vector<vector<char>>&mat,int n,int m,int i,int j,vector<vector<bool>>&visited){
    if(mat[i][j]=='.' && i>=0 && i<n && j>=0 && j<m && !visited[i][j])
    return true;
    return false;
}
void dfs_visit(vector<vector<bool>>&visited,vector<vector<char>>&mat,int x,int y){
    visited[x][y]=true;
    cout<<"Enter dfs_visit"<<"\n";
    cout<<"x="<<x<<" y="<<y<<"\n";
    for(int i=0;i<8;i++){
        if(check(mat,mat.size(),mat[0].size(),x+directions[i].second,y+directions[i].first,visited))
        dfs_visit(visited,mat,x+directions[i].second,y+directions[i].first);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    */
    //cout<<"Hello World"<<"\n";
    int n,m,i,j,k,c;
    cin>>n>>m;
    vector<vector<char>>mat(n,vector<char>(m,' '));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    c=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j]=='.' && !visited[i][j]){
                dfs_visit(visited,mat,i,j);
                c++;
            }
        }
    }
    cout<<c;
    return 0;
}