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
        int n,i,j,k,l=-1,h1=-1,ans=0;
        cin>>n;
        vector<int>a(n);
        unordered_map<int,int>m;
        int ele,h=0;
        for(i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
            if(m[a[i]]>h){
                h=m[a[i]];
                ele=a[i];
            }
        }
        unordered_set<int>S;
        for(auto it:m){
            if(it.second==h){
                S.insert(it.first);
            }
        }
        int pre,suff,c1=0,c2=0;
        if(S.count(a[0])){
            pre=a[0];
            for(i=1;i<n;i++){
                if(a[i]==a[i-1]){
                    c1++;
                }
            }
        }
        if(S.count(a[n-1])){
            suff=a[n-1];
            for(i=n-2;i>=0;i--){
                if(a[i]==a[i+1]){
                    c2++;
                }
            }
        }
        if(c1!=0 || c2!=0){
            if(c1>=c2){
                ele=pre;
            }
            else
            ele=suff;
        }
        for(i=0;i<n;i++){
            if(a[i]!=ele){
                l=i;
                break;
            }
        }
        for(i=n-1;i>=0;i--){
            if(a[i]!=ele){
                h1=i;
                break;
            }
        }
        c1=1,c2=1;
        for(i=1;i<n;i++){
            if(a[0]==a[i]){
                c1++;
            }
            else
                break;
        }
        for(j=n-2;j>=0;j--){
            if(a[j]==a[n-1]){
                c2++;
            }
            else
                break;
        }
        if(a[0]!=a[n-1]){
            ans=min(h1-l+1,n-max(c1,c2));
        }
        else{
            ans=max(ans,n-(c1+c2));
        }
        // if(h1==l && h1==-1){
        //     cout<<0<<"\n";
        // }
        // else
        // cout<<(h1-l+1)<<"\n";
        cout<<ans<<"\n";
    }
    return 0;
}