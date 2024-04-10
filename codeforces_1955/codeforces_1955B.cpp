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
        ll i,j,k,n,c,d,a11=INT_MAX,flag=0;
        cin>>n>>c>>d;
        vector<ll>a(n*n),temp;
        for(i=0;i<n*n;i++){
            cin>>a[i];
            a11=min(a11,a[i]);
        }
        sort(a.begin(),a.end());
        vector<vector<ll>>v(n,vector<ll>(n,-1));
        temp.pb(a11);
        v[0][0]=a11;
        // for(i=0;i<n;i++){
        //     for(j=0;j<n;j++){
        //         if(i+1 < n && v[i+1][j]==-1){
        //             v[i+1][j]=v[i][j]+c;
        //             temp.pb(v[i+1][j]);
        //         }                    
        //         if(j+1 < n && v[i][j+1]==-1){
        //             v[i][j+1]=v[i][j]+d;
        //             temp.pb(v[i][j+1]);
        //         }                    
        //     }
        // }
        // v[0][0] = a11;
    
        // Fill the first row
        for (int j = 1; j < n; ++j) {
            v[0][j] = v[0][j - 1] + d;
            temp.pb(v[0][j]);
        }
        
        // Fill the first column
        for (int i = 1; i < n; ++i) {
            v[i][0] = v[i - 1][0] + c;
            temp.pb(v[i][0]);
        }
        
        // Fill the remaining elements
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                v[i][j] = v[i][j - 1] + d;
                temp.pb(v[i][j]);
                if(v[i][j]!=v[i-1][j]+c){
                    flag=1;
                    break;
                }
            }
            // for (int j = 1; j < n; ++j) {
            //     v[i][j] = v[i - 1][j] + c;
            // }
            if(flag==1)
                break;
        }
        sort(temp.begin(),temp.end());
        // ll flag=0;
        if(temp.size()!=a.size())
            flag=1;
        else{
                for(i=0;i<n*n;i++){
                if(temp[i]!=a[i]){
                    flag=1;
                    break;
                }
            }        
        }
        if(flag==1) 
            cout<<"NO"<<"\n";
        else
            cout<<"YES"<<"\n";
    }
    return 0;
}