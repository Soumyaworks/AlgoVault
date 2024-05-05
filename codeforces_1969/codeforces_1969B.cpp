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
        ll n,i,j,k;
        string s;
        cin>>s;
        n=s.size();
        vector<ll>ind;
        for(i=0;i<n;i++){
            if(s[i]=='0')
                ind.pb(i);
        }
        if(ind.size()==n)
            cout<<0<<"\n";
        else{
            ll f=0;
            ll ans=0;
            for(i=0;i<n;i++){
                // if(s[i]=='1'){
                //     // cout<<"1 here : "<<i<< "\n";
                //     auto x = upper_bound(ind.begin(),ind.end(),i);
                //     if(x == ind.end())
                //         break;
                //     // 
                //     k = x - ind.begin();
                //     // cout<< "k="<<k<<"\n";
                //     k=ind[k];
                //     ans+=(k-i+1);
                //     ind.erase(x);
                //     swap(s[i],s[k]);
                // }
                // cout<<"printing string : "<<s<<"\n";
                // cout<<"printing vec : "<<"\n";
                // for(auto it:ind)
                //     cout<<it<<",";
                // cout<<"\n";
                if(s[i]=='0')
                    ans += f + (f>0);
                else
                    f++;
            }
            cout<<ans<<"\n";
        }

    }
    return 0;
}