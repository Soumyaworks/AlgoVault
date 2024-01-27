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
        ll n,k,i,j,p;
        cin>>n>>k;
        vector<ll>a(n);
        vector<ll>store;
        // unordered_set<ll>S;
        for(i=0;i<n;i++){
            cin>>a[i];
            // S.insert(a[i]);
        }
        if(k>=3){
            cout<<0<<"\n";
            continue;
        }
        ll ans=LLONG_MAX;
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                ans=min(ans,abs(a[i]-a[j]));
                store.eb(abs(a[i]-a[j]));
            }
        }
        // if(k>=3){
        //     cout<<0<<"\n";
        // }
        if(k==1){
            ans=min(ans,*min_element(a.begin(),a.end()));
            cout<<ans<<"\n";
        }
        else if(k==2){
            // a.resize(n+1);
            if(ans==0){
                cout<<0<<"\n";
                continue;
            }
            // n++;
            // for(p=0;p<store.size();p++){
            //     a.pb(store[p]);
            //     // n++;
            //     // cout<<"display a:\n";
            //     // for(auto it:a){
            //     //     cout<<it<<" ";
            //     // }
            //     // cout<<"\n";
            //     for(i=0;i<n-1;i++){
            //         for(j=i+1;j<n;j++){
            //             ans=min(ans,abs(a[i]-a[j]));
            //         }
            //     }
            //     a.pop_back();
            // }

            sort(a.begin(),a.end());
            for(p=0;p<store.size();p++){
                auto x=lower_bound(a.begin(),a.end(),store[p]);
                ll ind=distance(a.begin(),x);
                // cout<<"store[p]="<<store[p]<<" a[ind]="<<a[ind]<<"\n";
                ans=min(ans,abs(store[p]-a[ind]));
                if(ind>0){
                    ans=min(ans,abs(store[p]-a[ind-1]));
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}