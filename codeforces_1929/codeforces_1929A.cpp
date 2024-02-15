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

void swap(ll& a, ll& b) {
    ll temp = a;
    a = b;
    b = temp;
}

// Function to generate all permutations of an array
void permute(vector<ll>& arr, ll l, ll r,ll &ans) {
    if (l == r) {
        // Print the permutation
        // for (int i = 0; i <= r; ++i) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        ll i,s=0;
        for(i=1;i<=r;i++){
            s+=(arr[i]-arr[i-1]);
        }
        ans=max(ans,s);
    } else {
        for (int i = l; i <= r; ++i) {
            // Swap current element with the first element
            swap(arr[l], arr[i]);
            // Recursively generate permutations for the remaining elements
            permute(arr, l + 1, r,ans);
            // Backtrack by restoring the array to its original state
            swap(arr[l], arr[i]);
        }
    }
}

// Function to find all permutations of an array and print them
ll findAllPermutations(vector<ll>& arr) {
    ll ans=0;
    permute(arr, 0, arr.size() - 1,ans);
    return ans;
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
        ll n,i,j,k;
        cin>>n;
        vector<ll>arr(n);
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        // cout<<findAllPermutations(arr)<<"\n";
        ll s=0;
        for(i=1;i<arr.size();i++){
            s+=(arr[i]-arr[i-1]);
        }
        cout<<s<<"\n";

    }
    return 0;
}