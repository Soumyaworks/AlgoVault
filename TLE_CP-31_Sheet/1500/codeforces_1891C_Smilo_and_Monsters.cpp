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
    int t;
    cin>>t;
    while(t--){
        ll n,i,j,k=0,ans=0;
        cin>>n;
        vector<ll>a(n);
        for(auto &x:a) cin>>x;
        sort(a.begin(),a.end());
        i=0,j=n-1;
        k=accumulate(a.begin(),a.end(),0LL);
        ans=(k+1)/2;
        k/=2;
        // while(i<j){
        //     if((a[i]+k)>=a[j]){
        //         a[i]-=(a[j]-(a[i]+k));
        //         k=0;
        //         j--;
        //         ans+=1+a[i];
        //     }
        //     else{
        //         ans+=a[i];
        //         k+=a[i];
        //     }            
        //     i++;
        // }
        // if(i==j){
        //     if(k>=a[j])
        //         ans+=1;
        //     else{
        //         a[j]-=k;
        //         ans+=(k>0)?1:0;
        //         ans+=(a[j]+1)/2;
        //     }
        // }
        while(k>0){
            k-=a[j];
            ans++;
            j--;
        }

        cout<<ans<<"\n";
    }
    return 0;
}