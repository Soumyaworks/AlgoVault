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
    ll t;
    cin>>t;
    while(t--){
        ll m,n,i,j,k,p;
        cin>>n>>m>>k;
        unordered_set<ll>S1,S2;
        for(i=0;i<n;i++){
            cin>>j;
            S1.insert(j);
        }
        for(i=0;i<m;i++){
            cin>>p;
            S2.insert(p);
        }
        // cout<<"S1"<<"\n";
        // for(auto it:S1)
        //     cout<<it<<" ";
        // cout<<"\n";
        // cout<<"S2"<<"\n";
        // for(auto it:S2)
        //     cout<<it<<" ";
        // cout<<"\n";
        ll f=0,i1=0,i2=0;
        ll ans=true;
        // for(i=1;i<=k;i++){
        //     if(f==0 && S1.find(i)!=S1.end()){
        //         f=1;
        //         i1++;
        //         // cout<<"here1"<<"i="<<i<<"i1="<<i1<<"\n";
        //     }
        //     else if(f==1 && S2.find(i)!=S2.end()){
        //         f=0;
        //         i2++;
        //         // cout<<"here2"<<"i="<<i<<"i2="<<i2<<"\n";
        //     }
        //     else{
        //         if(f==0 && S1.find(i)==S1.end()){
        //             if(S2.find(i)!=S2.end()){
        //                 i2++;
        //                 // cout<<"here3"<<"i="<<i<<"i2="<<i2<<"\n";
        //             }
        //             else{
        //                 ans=false;
        //                 break;
        //             }
        //         }
        //         else if(f==1 && S2.find(i)==S2.end()){
        //             if(S1.find(i)!=S1.end()){
        //                 i1++;
        //                 // cout<<"here4"<<"i="<<i<<"i1="<<i1<<"\n";
        //             }
        //             else{
        //                 ans=false;
        //                 break;
        //             }
        //         }
        //     }
        //     if(i1>(k/2) || i2>(k/2)){
        //             ans=false;
        //             break;
        //         }
        // }
        // if(ans==true && i1==(k/2) && i2==(k/2))
        //     cout<<"YES"<<"\n";
        // else    {
        //     i1=0;
        //     i2=0;
        //     f=0;
        //     for(i=1;i<=k;i++){
        //     if(f==1 && S1.find(i)!=S1.end()){
        //         f=0;
        //         i1++;
        //         // cout<<"here1"<<"i="<<i<<"i1="<<i1<<"\n";
        //     }
        //     else if(f==0 && S2.find(i)!=S2.end()){
        //         f=1;
        //         i2++;
        //         // cout<<"here2"<<"i="<<i<<"i2="<<i2<<"\n";
        //     }
        //     else{
        //         if(f==1 && S1.find(i)==S1.end()){
        //             if(S2.find(i)!=S2.end()){
        //                 i2++;
        //                 // cout<<"here3"<<"i="<<i<<"i2="<<i2<<"\n";
        //             }
        //             else{
        //                 ans=false;
        //                 break;
        //             }
        //         }
        //         else if(f==0 && S2.find(i)==S2.end()){
        //             if(S1.find(i)!=S1.end()){
        //                 i1++;
        //                 // cout<<"here4"<<"i="<<i<<"i1="<<i1<<"\n";
        //             }
        //             else{
        //                 ans=false;
        //                 break;
        //             }
        //         }
        //     }
        //     if(i1>(k/2) || i2>(k/2)){
        //             ans=false;
        //             break;
        //         }
        //     }
        //     if(ans==true && i1==(k/2) && i2==(k/2))
        //     cout<<"YES"<<"\n";
        //     else
        //     cout<<"NO"<<"\n";
        // }
            // cout<<"NO"<<"\n";
        unordered_set<ll>S3;
        for(i=1;i<=k;i++){
            if(S1.count(i) && S2.count(i)){
                S3.insert(i);
            }
            else if(S1.count(i))
                i1++;
            else if(S2.count(i))
                i2++;
            else{
                ans=false;
                break;
            }
        }
        for(auto it:S3){
            if(i1<=i2){
                i1++;
            }
            else
                i2++;
        }
        if(ans==true && i1==(k/2) && i2==(k/2))
            cout<<"YES"<<"\n";
            else
            cout<<"NO"<<"\n";
        S1.clear();
        S2.clear();

    }
    return 0;
}