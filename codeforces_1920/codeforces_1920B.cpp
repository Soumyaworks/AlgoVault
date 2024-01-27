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
    ll t;
    cin>>t;
    while(t--){
        ll n,x,i,k,j;
        cin>>n>>k>>x;
        vector<ll>a(n),b(n);
        ll ans;
        for(i=0;i<n;i++){
            cin>>a[i];
            // a[i]=b[i];
        }
        sort(a.rbegin(),a.rend());
        for(i=0;i<n;i++){
            if(i==0)
                continue;
            else{
                a[i]+=a[i-1];
            }
        }
        // cout<<"A here :"<<"\n";
        // for(auto it:a){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        ans=a[x-1]*-1;
        ans=a[n-1]+2*ans;
        // cout<<"ans here ="<<ans<<"\n";
        ll csum=ans;
        x--;
        for(i=0;i<k;i++){
            csum=-1*(a[min(i+1+x,n-1)]-a[i])+(a[n-1]-a[min(i+1+x,n-1)]);
            ans=max(ans,csum);
        }
        cout<<ans<<"\n";

    }
    return 0;
}