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
    
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    
    //cout<<"Hello World"<<"\n";
    int t,n,z,i,j,k,c,p;
    cin>>t;
    for(z=1;z<=t;z++){
        cin>>n;
        p=0;
        char mat[n][n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
            cin>>mat[i][j];
        }
        map<int,set<pair<int,int>>>M;
        for(i=0;i<n;i++){
            k=0;
            c=0;
            vector<int>v;
            for(j=0;j<n;j++){
                if(mat[i][j]=='O'){
                    k=1;
                    break;
                }
                if(mat[i][j]=='.'){
                    c++;
                    v.pb(j);
                }
            }
            if(k==1)
            continue;
            else{
                for(auto it:v){
                    M[c].insert(make_pair(i,it));
                }
                p=1;
            }
        }
        for(i=0;i<n;i++){
            k=0;
            c=0;
            vector<int>v;
            for(j=0;j<n;j++){
                if(mat[j][i]=='O'){
                    k=1;
                    break;
                }
                if(mat[j][i]=='.'){
                    c++;
                    v.pb(j);
                }
            }
            if(k==1)
            continue;
            else{
                for(auto it:v){
                    M[c].insert(make_pair(i,it));
                }
                p=1;
            }
        }
        if(p==0){
            cout<<"Case #"<<z<<": "<<"Impossible"<<"\n";
        }
        else{
            j=0;
            for(auto it:M){
                cout<<"it.first="<<it.first<<" it.second="<<it.second.size()<<"\n";
                if(j==0){
                    k=it.first;
                    p=it.second.size();
                    break;
                }
                j++;
            }
            cout<<"Case #"<<z<<": "<<k<<" "<<p<<"\n";
        }
    }
    return 0;
}