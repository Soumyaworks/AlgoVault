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
#define indexed_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
using namespace __gnu_pbds;

// Defllion for a Linked List
struct ListNode {
    ll val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(ll x) : val(x), next(nullptr) {}
    ListNode(ll x, ListNode *next) : val(x), next(next) {}
    //ListNode *head=new ListNode();
    //ListNode *ptr1,*ptr2;
};

// Definition for a binary tree node.
struct TreeNode {
    ll val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    //TreeNode *root=new TreeNode();
};

void search(ll x, vector<ll>&v, unordered_map<ll,ll>&M){
    ll n = v.size();
    // if(x==n-1){
    //     M[x]=n-1;
    //     return 0;
    // }
    // if(M.count(x)==0){
    //     M[x]=min(n+1,M[x+1]);
        // cout<<"M[x] here: "<<M[x]<<"\n";
        // if(M[x+1]<=n)
        // return M[x]-x-1;
        // else
        //     return M[x]-x;
    // }
    //     return n-x+1;
    // else
    // return min(M[x],M[x+1])-x-1;
    M[x]=min(M[x], M[x+1]);
}

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
        ll i,j,k,n,m;
        cin>>n>>m;
        unordered_map<ll,ll>M;
        for(i=1;i<=n;i++)
            M[i]=n;
        for(i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            j=u;
            if(v<u){
                u=v;
                v=j;
            }
            if(M.count(u))
                M[u]=min(M[u],v-1);
            else
                M[u]=v-1;
            // if(M.count(v))
            //     M[v]=min(M[v],u);
            // else
            //     M[v]=u;
        }
        // M[n]=n+1;
        vector<ll>v(n);
        ll ans=0;
        for(i=0;i<n;i++)
            v[i]=i+1;
        for(i=n-1;i>=0;i--){
            search(i,v,M);
            // cout<<"returned value here: "<<k<<"\n";
            ans+=(M[i]-i);
        }
        // for(i=0;i<n;i++)
        //     ans+=(M[i]-i);
        cout<<ans+n<<"\n";
    }
    return 0;
}