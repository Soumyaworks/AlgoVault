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
#define mod2 1000000005
#define fill(a,x) memset(a,x,sizeof(a))
#define indexed_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
using namespace __gnu_pbds;

// Attributes : https://cp-algorithms.com/algebra/binary-exp.html
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

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res%mod;
}

/*
ll div1(ll a,ll b)
{
    return (a%mod*(modpow(b,mod-2)%mod))%mod;
}
*/
ll sol1(ll n,ll r){
    ll ans=1;
    ll k=min(r,n-r);
    for(ll i=0;i<k;i++)
    {
        ans=(ans%mod*(n-i)%mod)%mod;
        //ans=div1(ans,i+1);
        ans=(ans%mod*(modpow(i+1,mod2)%mod))%mod;
        cout<<"ans for i="<<i<<" :"<<ans<<"\n";
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
    ll t,i,j,k,n,p,c1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll c[n];
        set<ll>S;
        unordered_map<ll,ll>mymap;
        ll f=0;
        for(i=0;i<n;i++)
        {
            cin>>c[i];
            mymap[c[i]]++;
        }
        c1=0;
        k=*max_element(c,c+n);
        if(n==1)
        cout<<2<<"\n";
        else{
        /*
        for(auto it:mymap)
        {
            
            
            
                j=it.se;
                S.insert(it.se);
            
            c1++;
        }
        
        if(c1==1)
        cout<<2<<"\n";
        else{
        if(S.size()!=1)
        f=1;
        if(f==1)
        cout<<modpow(2,n,mod)<<"\n";
        else
        {
            p=modpow(2,n,mod);
            k=n*j;
            cout<<p-k<<"\n";
        }
        }
        */
        cout<<"k="<<k<<" mymap[k]="<<mymap[k]<<"\n";
        if(mymap[k]&1)
        {
            p=modpow(2,n)%mod;
            p=(p<0)?(p+mod)%mod:p;
            cout<<p<<"\n";
        }
        else
        {
            j=1;
            i=0;
            /*
            while(i<min(mymap[k]/2,mymap[k]-(mymap[k]/2)))
            {
                
                //j=j%mod;
                //p=(n-i)%mod;
                //j=(j*p)%mod;
                
                j=((j%mod)*(n-i)%mod)%mod;

                p=modpow(i+1,mod2)%mod;
                //ll x=(j%mod*p%mod)%mod;
                //j=x;
                j=((j%mod) *(p%mod))%mod;
                cout<<"j for i="<<i<<" :"<<j<<"\n";
                i++;
            }

            j%=mod;
            p=modpow(2,n-mymap[k])%mod;
            cout<<"p=p2="<<p<<"\n";
            p=((p%mod)*(j%mod))%mod;
            j=modpow(2,n)%mod-p;
            cout<<"j in else="<<j<<"\n";
            j=j<0?((j+mod)%mod):j;
            */
            /*
            ll ans,p1,p2;
            ans=modpow(2,n)%mod-((modpow(2,n-mymap[k])%mod)*sol1(mymap[k],mymap[k]/2)%mod)%mod;
            //j=modpow(2,n)%mod;

                //p1=sol1(mymap[k],mymap[k]/2)%mod;
                p1=1;
                
                k=min(mymap[k]/2,mymap[k]-(mymap[k]/2));
                for(ll i=0;i<k;i++)
                {
                    p1=(p1%mod*(n-i)%mod)%mod;
                    //ans=div1(ans,i+1);
                    p1=(p1%mod*(modpow(i+1,mod2)%mod))%mod;
                    cout<<"ans for i="<<i<<" :"<<p1<<"\n";
                }
                //return ans;
                cout<<"p1="<<p1<<"\n";
                p2=(modpow(2,n-mymap[k])%mod);
                cout<<"p2="<<p2<<"\n";
                cout<<"ans in else="<<ans<<"\n";
            */
            //cout<<j<<"\n";

            //cout<<(modpow(2,n,mod)-p)<<"\n";
        }
        }
    }
    return 0;
}