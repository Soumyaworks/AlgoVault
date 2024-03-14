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

ll gcd(ll a, ll b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the Least Common Multiple (LCM)
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

// Function to count common multiples of x and y up to n
ll countCommonMultiples(ll x, ll y, ll n) {
    // Calculate LCM of x and y
    ll lcm_xy = lcm(x, y);

    // Count multiples of lcm_xy within the range [1, n]
    return n / lcm_xy;
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
        ll x,i,j,k,y,n;
        cin>>n>>x>>y;
        ll idx = countCommonMultiples(x,y,n);
        // cout<<"idx = "<<idx<<"\n";
        // ll h=(n/x)-idx;
        ll h = (n/x) - idx;
        ll low=(n/y)-idx;
        // cout<<"h="<<h<<" ,low = "<<low<< "\n";
        ll ans=0;
        // i=n;
        // while(h--){
        //     ans+=i;
        //     i--;
        // }
        // i=1;
        h = n - h;
        ll shigh = (n*(n+1))/2 - (h*(h+1))/2;
        // while(low--){
        //     ans-=i;
        //     i++;
        // }
        ll slow = (low*(low+1))/2;
        ans = shigh - slow;
        cout<<ans<<"\n";
    }
    return 0;
}