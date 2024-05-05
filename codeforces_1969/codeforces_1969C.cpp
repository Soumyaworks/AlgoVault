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
        ll n,i,j,k;
        cin>>n>>k;
        ll sum=0;
        vector<ll>a(n);
        for(i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        vector<ll>drop;
        
        while(k--){
            ll maxdrop=LLONG_MIN;
            ll ind=-1;
            for(i=0;i<n;i++){
                ll left=0,right=0;
                if(i>0)
                    left=max((ll)0,a[i-1]-a[i]);
                if(i<n-1)
                    right = max((ll)0,a[i+1]-a[i]);
                // drop.pb(left);
                // drop.pb(right);
                if(left>maxdrop){
                    maxdrop=left;
                    ind=i-1;
                }
                if(right>maxdrop){
                    maxdrop=right;
                    ind=i+1;
                }                
            }
            if(ind!=-1)
                a[ind]-=(maxdrop!=INT_MIN)?maxdrop:0;
            // cout<<"printing the array : "<<"\n";
            // for(auto x:a)
            //     cout<<x<<" ";
            // cout<<"\n";
        }
        sum=0;
        for(auto x:a)
            sum+=x;
        cout<<sum<<"\n";
        
    }
    return 0;
}