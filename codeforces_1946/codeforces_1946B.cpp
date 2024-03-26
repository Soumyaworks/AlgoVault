//Author : Soumya Banerjee
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("Ofast")
// #define ll long long int
#define ll int64_t
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

ll binpow(ll a, ll b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
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
        // ll i,j,k,n;
        // cin>>n>>k;
        // vector<ll>a(n);
        // for(i=0;i<n;i++){
        //     cin>>a[i];
        // }

        // ll max_so_far = LLONG_MIN, max_ending_here = 0, s=0;
        // ll start = 0, end = 0,p=0;
 
        // for (i = 0; i < n; i++) {
        //     // max_ending_here = max_ending_here + a[i];
        //     // if (max_so_far < max_ending_here)
        //     //     max_so_far = max_ending_here;
    
        //     // if (max_ending_here < 0)
        //     //     max_ending_here = 0;
        //     max_ending_here += a[i];

        //     if (max_so_far < max_ending_here) {
        //         max_so_far = max_ending_here;
        //         start = p;
        //         end = i;
        //     }

        //     if (max_ending_here < 0) {
        //         max_ending_here = 0;
        //         p = i + 1;
        //     }
        //     s+=a[i];
        //     // if(s>0)
        //     //     s=s%mod;
        //     // else
        //     //     s=((s % mod) + mod) % mod;

        // }
        // // cout<<"max_so_far ; "<<max_so_far<<"\n";
        // // ll ans = max_so_far;
        // // // ans=max((ll)0,ans);
        // // if(ans>0){
        // //     // cout<<"ans within : "<<ans<<"\n";
        // //     // ll t=(ll)pow(2,k);
        // ll t = binpow(2,k);
        // //     // cout<<"t="<<t<<"\n";
        // //     // ans = (ans*t)%mod;
        // //     ans = ans*t;
        // //     ll j=0;
        // //     for(i=start;i<=end;i++)
        // //         j+=a[i];
        // //     // cout<<"before j = "<<j<<"\n";
        // //     // cout<<"ans before : "<<ans<<"\n";
        // //     j=s-j;
        // //     // ans=(ans+j)%mod;
        // //     ans+=j;
        // //     ans=ans%mod;
        // //     // cout<< "start = "<<start<< " end = "<<end<< " j="<<j<<"\n";
        // //     // cout<<" ans after : "<<ans<<"\n";
        // // }
        // // else{
        // //     ans=s;
        // //     ans=((ans % mod) + mod) % mod;

        // // }
        // s=((s % mod) + mod) % mod;
        // ll ans=max_so_far;
        // ans=ans%mod;
        // ll fans;
        // fans = (s + ans * t - ans + mod) % mod;
        // // ans=ans%mod;
        // // ans=((ans % mod) + mod) % mod;
        // cout<<fans<<"\n";
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll S = 0, sum = 0;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            cur += a[i];
            cur = max(cur, (ll)0);
            S = max(S, cur);
        }
        sum = (sum % mod + mod) % mod;
        S = S % mod;
        ll t = 1;
        for (int i = 0; i < k; i++) {
            t = t * 2 % mod;
        }
        ll ans = (sum + S * t - S + mod) % mod;
        cout << ans << '\n';
    }
    return 0;
}