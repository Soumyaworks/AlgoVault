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
        // idea is: we don't want many disconnected components, so start with those vertices having max degrees
        // color such edges with k colors each time, and such vertices' weights will get added each time
        ll i,j,k,n,ans=0;
        cin>>n;
        vector<ll>w(n);
        for(auto &x:w)
            cin>>x, ans+=x;
        unordered_map<ll,ll>degree;
        for(i=0;i<n-1;i++){
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            degree[x]++;
            degree[y]++;
        }
        // to store the weights in decreasing order along with the index
        priority_queue<pair<ll,ll>>pq;
        for(i=0;i<n;i++){
            pq.push({w[i],i});
        }
        for(i=0;i<n-2;i++){
            cout<<ans<<" ";
            while(!pq.empty()){
                auto x = pq.top();
                pq.pop();
                if(degree[x.se] > 1){
                    ans+=x.fi;
                    degree[x.se]--;
                    pq.push({x.fi,x.se});
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}