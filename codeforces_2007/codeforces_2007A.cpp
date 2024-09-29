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

vector<ll>prime(1000000,1);
//can use bool if n<=10^5
void sieve(ll n)
{
    ll i,j;

    prime[0]=prime[1]=0;
    for(i=2;i*i<=n;i++)
    {
        if(prime[i]==1)
        {
            for(j=i*i;j<=n;j+=i)
                prime[j]=0;
        }
    }
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
    // sieve(1005);
    int t;
    cin>>t;
    while(t--){
        int i,j,k=0,n,l,r;
        cin>>l>>r;
        int ans=0;
        for(i=l;i<=r;i++){
            if(i&1) k++;
        }
        ans = k/2;
        cout<<ans<<"\n";

    }
    return 0;
}