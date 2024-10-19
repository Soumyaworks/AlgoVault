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

ll minOperations(vector<ll>& arr, ll k) {
    // ll n = arr.size();
    // ll operations = 0;
    
    // vector<ll> lazy(n + 1, 0);  

    
    // for (ll i = n - 1; i >= 0; --i) {
    //     if (i + 1 < n) {
    //         lazy[i] += lazy[i + 1];
    //     }

    //     if (arr[i] - lazy[i] > 0) {
    //         int decAmount = arr[i] - lazy[i]; 
    //         operations++;

    //         lazy[i] += decAmount;
    //         if (i - k >= 0) {
    //             lazy[i - k] -= decAmount; 
    //         }
    //     }
    // }
    // return operations;

    // ll n = arr.size();
    // ll operations = 0;

    // return operations;

    ll maxElement = *max_element(arr.begin(), arr.end());
    ll sum=0;
    for(auto &x:arr) sum+=x;
    
    ll operations = (sum + k - 1) / k;

    return max(operations,maxElement);
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
        ll i,j,n,k;
        cin>>n>>k;
        vector<ll>arr(n);
        for(auto &x:arr) cin>>x;
        sort(arr.begin(),arr.end());
        cout<<minOperations(arr,k)<<"\n";
    }
    return 0;
}