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
        vector<vector<int>>matrix(2,vector<int>(n));
        for(i=0;i<2;i++){
            for(j=0;j<n;j++){
                if(i==0)
                matrix[i][j]=s1[j]-'0';
                else
                matrix[i][j]=s2[j]-'0';
            }
        }
        int m1=n-1,m2=0;
        for(i=n-1;i>=1;i--)
			if(matrix[0][i]==1 && matrix[1][i-1]==0) m1=i-1;
		for(i=0;i<m1;i++)
			if(matrix[1][i]==1 && matrix[0][i+1]==0) m2=i+1;
		for(i=0;i<=m1;i++) cout<<matrix[0][i];
		for(int i=m1;i<n;i++) cout<<matrix[1][i];
		cout<<"\n";
		cout<<m1-m2+1<<"\n";

    }
    return 0;
}