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

ll calculate(ll k, ll m){
    ll sum=0;
    if(m<=k){
        sum = (m*(m+1))/2;
    }   
    else{
        sum += (k*(k+1))/2;
        m-=k;
        ll p = k-1-m;
        sum += (k*(k-1))/2 - (p*(p+1))/2;
    }
    return sum;
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
        ll k,x,ans;
        cin>>k>>x;
        ll i,j,p;
        i=1,j=2*k-1;
        // ll total = (j*(j+1))/2;
        if(i==j)
            ans=1;
        else if(calculate(k,j) <= x){
            ans=j;
        }
        else{
            while(i<=j){
                ll mid = (i+j)/2;
                if(calculate(k,mid)>=x && calculate(k, mid-1)<x){
                    ans=mid;
                    break;
                }
                else if(calculate(k,mid)>=x && calculate(k,mid-1)>=x)
                    j=mid-1;
                else
                    i=mid+1;
            }
        }        
        cout<<ans<<"\n";
    }
    return 0;
}