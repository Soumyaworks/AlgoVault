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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin); 
    //     freopen("output.txt", "w", stdout); 
    // #endif 
    
    //cout<<"Hello World"<<"\n";
    ll n,i,j,k;
    cin>>n;
    vector<ll>a(n);
    ll c=0;
    for(auto &x:a){
        cin>>x;
        if(x==1) c++;
    }
    // if we already have 1s in the array, we can just use those to make other elements as 1s in every step
    if(c>0) cout<<n-c;
    else{
        // if we don't have 1s, then we need to find the min. length of subarray whose gcd is 1
        // min. length because then in min. steps, we can firstly make this subarray 1
        // then in the rest of the steps, we can make all the rest of the array elements 1, i.e in n-1 operations
        // so subarray between L and R whose gcd=1, having min. length is what we are wanting
        bool flag=false;
        k=INT_MAX;
        for(i=0;i<n-1;i++){
            ll gcd=a[i];
            for(j=i+1;j<n;j++){
                gcd = __gcd(gcd,a[j]);
                if(gcd==1){
                    flag=true;
                    k=min(k, j-i);
                    break;
                }
            }
        }
        // if no subarray present whose gcd is 1, we can't make all the elements as 1
        if(!flag) cout<<-1;
        else cout<<k+(n-1);
    }

    return 0;
}