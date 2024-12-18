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
    ll n,h,ans=0,k;
    cin>>n>>h;
    vector<ll>a(n);
    for(auto &x:a) cin>>x;
    for(ll i=0;i<n;i++){
        vector<ll>temp(a.begin(),a.begin()+i+1);
        // cout<<"printing temp:"<<"\n";
        // for(auto x:temp) cout<<x<<" ";
        // cout<<"\n";
        sort(temp.begin(),temp.end());
        ll s=0;
        ll th=h;
        ll hs=0;
        for(ll j=i;j>=0;){
            // if((hs+temp[j])>h){
            //     s+=((hs+temp[max(0LL,j-1)])<=h)?1:0;
            //     break;
            // }
            // else if((hs+temp[j])==h){
            //     s+=(j>=1)?2:1;
            //     break;
            // }
            // th-=temp[j];
            // s+=(j>=1)?2:1;
            hs+=temp[j];
            j-=2;
        }
        // cout<<"s at every step:"<<s<<"\n";
        // ans=max(ans,s);
        if(hs>h){
            ans=temp.size()-1;
            break;
        }
    }
    // for(auto x:a)  cout<<x<<",";
    // cout<<"\n";
    ans=(ans==0)?n:ans;
    cout<<ans<<"\n";
    return 0;
}