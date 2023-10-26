//Author : Soumya Banerjee
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
        int i,j,k,m,ans=INT_MAX;
        cin>>m;
        // vector<vector<int>>mat(2,vector<int>(m)),sum(3,vector<int>(m+1,0)),path(2,vector<int>(m,0)),minsum(3,vector<int>(m+1,0));
        vector<vector<int>>mat(2,vector<int>(m)),sum(2,vector<int>(m,0));
        for(i=0;i<2;i++){
            for(j=0;j<m;j++){
                cin>>mat[i][j];
                if(j==0)
                sum[i][j]=mat[i][j];
                else
                sum[i][j]=sum[i][j-1]+mat[i][j];
            }
        }
        // cout<<"sum matrix"<<"\n";
        // for(i=0;i<2;i++){
        //     for(j=0;j<m;j++){
        //         cout<<sum[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        // for(i=1;i<=2;i++){
        //     for(j=1;j<=m;j++){
        //         sum[i][j]=max(sum[i-1][j],sum[i][j-1])+mat[i-1][j-1];
        //         minsum[i][j]=min(minsum[i-1][j],minsum[i][j-1])+mat[i-1][j-1];
        //     }
        // }
        // cout<<"max path sum = "<<sum[2][m]<<"\n";

        // cout<<"sum matrix"<<"\n";
        // for(i=0;i<=2;i++){
        //     for(j=0;j<=m;j++){
        //         cout<<sum[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        // i=2;j=m;
        // while(i>0 && j>0){
        //     path[i-1][j-1]=1;
        //     if(sum[i-1][j]>sum[i][j-1]){
        //         i--;
        //     }
        //     else    
        //         j--;
        // }

        // // for(i=1;i<=2;i++){
        // //     for(j=1;j<=m;j++){
        // //         minsum[i][j]=min(minsum[i-1][j],minsum[i][j-1])+mat[i][j];
        // //     }
        // // }
        // cout<<"min path sum = "<<minsum[2][m]<<"\n";
        // int ans=0;
        // i=2;j=m;
        // while(i>0 && j>0){
        //     if(path[i-1][j-1]!=1)
        //         ans+=mat[i-1][j-1];
        //     // path[i-1][j-1]=1;
        //     if(minsum[i-1][j]>minsum[i][j-1]){
        //         i--;
        //     }
        //     else    
        //         j--;
        // }
        for(i=0;i<m;i++){
            if(i==0)
                j=sum[0][m-1]-sum[0][i];
            else if(i==m-1)
                j=sum[1][i-1];
            else
                j=max(sum[0][m-1]-sum[0][i],sum[1][i-1]);
            ans=min(ans,j);
        }
        cout<<ans<<"\n";

    }

    return 0;
}