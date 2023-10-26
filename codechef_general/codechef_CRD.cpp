#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("Ofast")
#define ll long long int
#define pb push_back
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

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll div1(ll a,ll b)
{
    return (a%mod*(binpow(b,mod-2)%mod))%mod;
}

ll sol1(ll n,ll r){
    ll ans=1;
    ll k=min(r,n-r);
    for(ll i=0;i<k;i++)
    {
        ans=(ans%mod*(n-i)%mod)%mod;
        ans=div1(ans,i+1);
        //cout<<"ans for i="<<i<<" :"<<ans<<"\n";
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    */
    //cout<<"Hello World"<<"\n";
    ll t,n,i,j,k,c,p1,p2;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n],ans;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll max=0,max_val=0;
        max=*max_element(a,a+n);
        for(i=0;i<n;i++)
        {
            if(max==a[i])
            max_val++;
        }
        if(n==1)
        {
            cout<<2<<"\n";
            continue;
        }
        else
        {
            //cout<<"max="<<max<<" max_val="<<max_val<<"\n";
            if(max_val%2!=0)
            ans=binpow(2,n)%mod;
            else
            {
                ans=binpow(2,n)%mod-((binpow(2,n-max_val)%mod)*sol1(max_val,max_val/2)%mod)%mod;
                //p1=sol1(max_val,max_val/2)%mod;
                //cout<<"p1="<<p1<<"\n";
                //p2=(binpow(2,n-max_val)%mod);
                //cout<<"p2="<<p2<<"\n";
                //cout<<"ans in else="<<ans<<"\n";
            }
            if(ans<0)
            ans=(ans+mod)%mod;
            cout<<ans<<"\n";
        }
        
    }
    return 0;
}