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
    // cout<<"t over here: "<<t <<"\n";
    while(t--){
        int i,j,k,n;
        cin>>n;
        // cout<<"n over here: "<<n <<"\n";
        vector<ll>a(n);
        for(i=0;i<n;i++)
            cin>>a[i];
        // cout<<"array printed initially"<<"\n";
        // for(auto x:arr)
        //     cout<<x<<" ";
        // cout<<"\n";
        // for(i=0;i<=20;i++){
        //     vector<ll>ind;
        //     j=0;
        //     // cout<<"entering loop"<<"\n";
        //     for(auto x:arr){
        //         if(((1<<i)&x)!=0){
        //             ind.pb(j);
        //             // cout<<"condition getting satisfied"<<"\n";
        //         }
                    
        //         j++;
        //         // cout<<x<<" ";
        //     }
        //     if(ind.size()>=2){
        //         for(j=1;j<ind.size();j++){
        //             ans=max(ans, ind[j]-ind[j-1]);
        //         }
        //         ans=max(ans, n - ind[ind.size()-1]);
        //     }
        //     else if(ind.size()==1){
        //         ans=max(ans, max(ind[0]+1, n - ind[0]));
        //         // break;
        //     }
        // }
        int ans = 1;
 
        for (int j = 0; j < 20; j++) {
            vector<int> ind;
            for (int i = 0; i < n; i++) {
                if (a[i] >> j & 1) ind.pb(i);
            }
            int mx = 0, last = -1;
            for (auto it : ind) {
                mx = max(mx, it - last);
                last = it;
            }
            mx = max(mx, n - last);
            if (last != -1) ans = max(ans, mx);
        }
 
        cout << ans << endl;
        // cout<<((ans==-1)?n:ans)<<"\n";
    }
    return 0;
}