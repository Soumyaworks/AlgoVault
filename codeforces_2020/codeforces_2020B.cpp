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

// ll countSquares(ll a, ll b)
// {
//     return (floor(sqrt(b)) - ceil(sqrt(a)) + 1);
// }

// bool check(ll mid, ll k){
//     ll psquares = countSquares(1,mid);
//     if(psquares>=k) return true;
//     return false;
// }

ll countSquares(ll b) {
    return floor((double)(sqrt((double)b)));
}

bool check(ll mid, ll k) {
    ll psquares = countSquares(mid);
    ll nonsquares = mid - psquares;
    return nonsquares >= k;
    // return psquares>=k;
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
        ll i,j,k,n,p;
        cin>>k;
        ll low = 0, high = LLONG_MAX, mid, ans=0;
        while(low<=high){
            mid = low + (high - low)/2;
            if(check(mid,k)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}