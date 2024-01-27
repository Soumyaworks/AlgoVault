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
    ll t,n,i,j,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<ll,ll>>a(n),b;
        for(i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i+1;
        }
        sort(a.begin(),a.end());
        ll p1=0,p2=n-1;
        ll ans=0;
        while(p1<p2){
            ll x=min(a[p1].first,a[p2].first);
            ans+=x;
            for(i=1;i<=x;i++){
                b.pb({a[p1].second,a[p2].second});
            }
            a[p1].first-=x;
            a[p2].first-=x;
            
            if(a[p1].first){
                p2--;
            }
            else{
                p1++;
            }            
        }
        cout<<ans<<"\n";
        for(auto it:b){
            cout<<it.first<<" "<<it.second<<"\n";
        }
    }
    return 0;
}