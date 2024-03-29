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
        int i,j,k,n;
        cin>>n;
        vector<vector<char>>v(2*n,vector<char>(2*n));
        if(n==1){
            v[0][0]=v[0][1]=v[1][0]=v[1][1]='#';
        }
        else{
            for(i=0;i<2*n;i++){
                for(j=0;j<2*n;j++){
                    char ch;
                    int r=i%4;
                    int c=j%4;
                    if((r==0 || r==1) && (c==0 || c==1))
                        ch='#';
                    else if((r==0 || r==1) && (c==2 || c==3))
                        ch='.';
                    else if((r==2 || r==3) && (c==0 || c==1))
                        ch='.';
                    else 
                        ch='#';
                    v[i][j]=ch;                    
                }
            }
        }
        for(i=0;i<2*n;i++){
            for(j=0;j<2*n;j++)
                cout<<v[i][j];
            cout<<"\n";
        }
    }
    return 0;
}