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
    int dx[]={-1,-1,1,1};
    int dy[]={-1,1,-1,1};
    while(t--){
        int a,b,xk,yk,xq,yq,i,j,k,p,q;
        cin>>a>>b;
        cin>>xk>>yk;
        cin>>xq>>yq;
        set<pair<int,int>>S;
        int ans=0;
        for(k=1;k<=2;k++){
            if(k%2){
                p=a;
                q=b;
            }
            else{
                p=b;
                q=a;
            }
        // p=a;
        // q=b;
        for(i=0;i<4;i++){
            int x=xk+dx[i]*p;
            int y=yk+dy[i]*q;
            // cout<<"==================\n";
            // cout<<"i="<<i<<" x="<<x<<" y="<<y<<"\n";
            for(j=0;j<4;j++){
                if(i!=j){
                    int xq1=x-dx[j]*p;
                    int yq1=y-dy[j]*q;
                    // cout<<"j="<<j<<" xq1="<<xq1<<" yq1="<<yq1<<"\n";
                    if(xq1==xq && yq1==yq){
                        // cout<<"Match\n";
                        S.insert({x,y});
                        ans++;
                    }
                }
            }
            swap(p,q);
            for(j=0;j<4;j++){
                int xq1=x-dx[j]*p;
                int yq1=y-dy[j]*q;
                // cout<<"inside 2nd for"<<"\n";
                // cout<<"j="<<j<<" xq1="<<xq1<<" yq1="<<yq1<<"\n";
                if(xq1==xq && yq1==yq){
                    ans++;
                    // cout<<"Match\n";
                    S.insert({x,y});
                }
            }
            swap(p,q);
        }
        // cout<<ans<<"\n";
        }
        cout<<S.size()<<"\n";
    }
    return 0;
}