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



ll countDivisionsBy3(ll n) {
   if (n <= 0) return 0;
    // double logResult = (log(n)*1.0) / (log(3)*1.0);
    // ll divisions = static_cast<ll>(floor(logResult)) + 1;
    // double f = ceil(log(n)/log(3));
    // double f = ceil(log3(n));
    ll divisions = (log(n)/(log(3)*1.0))+1;

    return divisions;
}

// ll countDivisionsBy3(ll n) {
//    ll count=0;
//    while(n>0){
//         n/=3;
//         count++;
//    }
//    return count;
// }

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
        ll l,r;
        cin>>l>>r;
        // vector<ll>v;
        priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
        for(i=l;i<=r;i++)
            pq.push(i);
        ll x = pq.top();
        pq.pop();
        ll times = countDivisionsBy3(x);
        ll ans=times;
        while(times--){
            ll x = pq.top();
            x*=3;
            pq.pop();
            pq.push(x);
        }
        while(!pq.empty()){
            ll x = pq.top();
            pq.pop();
            ans+=countDivisionsBy3(x);
        }
        cout<<ans<<"\n";        
    }
    return 0;
}