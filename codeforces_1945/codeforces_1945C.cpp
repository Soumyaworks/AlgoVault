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
        ll i,j,k,n;
        cin>>n;
        string s;
        cin>>s;
        vector<pair<ll,ll>>prefix(n,{0,0});
        for(i=0;i<n;i++){
            if(i==0){
                prefix[i].fi=(s[i]=='0')?1:0;
                prefix[i].se=(s[i]=='1')?1:0;
            }
            else{
                prefix[i].fi=prefix[i-1].fi + (s[i]=='0')?1:0;
                prefix[i].se=prefix[i-1].se + (s[i]=='1')?1:0;
            }
        }
        ll dist=INT_MAX,ans;
        for(i=-1;i<=n;i++){
            ll zeros=0,ones = 0,left,right;
            if(i==-1){
                ones = prefix[n-1].se;
            }
            else if(i==n){
                zeros = prefix[i].fi;
            }
            else{
                zeros = prefix[i].fi;
                ones = prefix[n-1].se - prefix[i].se;
            }
            left = (i+1)/2;
            right = (n-i)/2;
            if(i==-1){
                left = 0;
                right = (n+1)/2;
            }
            else if(i==n){
                left = (n+1)/2;
                right = 0;
            }
            if(zeros >= left && ones >= right){
                if(abs(n/2 - i)<dist){
                    dist = abs(n/2 - i);
                    ans = i;
                }
                // ans = min(ans, abs(n/2 -i));
            }
        }
        // ans=(ans==INT_MAX)?0:ans;
        ans = (ans==n)?(ans-1):ans;
        cout<<ans+1<<"\n";

    }
    return 0;
}