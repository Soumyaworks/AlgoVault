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
        ll n,i,j,k;
        cin>>n;
        unordered_set<ll>S1;
        unordered_map<ll,ll>mymap;
        for(i=0;i<n;i++){
            cin>>k;
            S1.insert(k);
        }
        vector<pair<ll,ll>>v;
        for(auto it:S1){
            v.pb({it+n,it+1});
        }
        
        sort(v.begin(),v.end());
        // cout<<"printing the array : "<<"\n";
        // for(auto it:v){
        //     cout<<it.se << ","<< it.fi<<"\n";
        // }
        ll ans=1,maxans=1;
        j=0;
        vector<ll>temp;
        ll curr=v[0].fi;
        temp.pb(curr);
        for(i=1;i<v.size();i++){
            if(v[i].se<=curr){
                ans++;
                temp.pb(v[i].fi);
            }
            else{
                maxans=max(maxans,ans);
                temp.pb(v[i].fi);
                auto it=lower_bound(temp.begin(),temp.end(),v[i].se);
                curr=temp[it-temp.begin()];
                // cout<<"curr = "<<curr<<"\n";
                j=(it-temp.begin());
                // cout<<"j="<<j<<"\n";
                ans=i-j+1;
                // cout<<"new ans = "<<ans<<"\n";
                // curr=v[i].fi;

            }
        }
        maxans=max(maxans,ans);
        cout<<maxans<<"\n";
    }
    return 0;
}