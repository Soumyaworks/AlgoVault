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
        int n,i,j,k;
        cin>>n;
        vector<pair<int,int>>s(n),m(n),b(n);
        for(i=0;i<n;i++){
            cin>>s[i].fi;
            s[i].se=i;
        }
        for(i=0;i<n;i++){
            cin>>m[i].fi;
            m[i].se=i;
        }
        for(i=0;i<n;i++){
            cin>>b[i].fi;
            b[i].se=i;
        }
        i=j=k=0;
        sort(s.rbegin(),s.rend()); //i
        sort(m.rbegin(),m.rend()); //j
        sort(b.rbegin(),b.rend()); //k
        int ans=0;
        // while(true){
        //     if(s[i].se!=m[j].se && s[i].se!=b[k].se && m[j].se!=b[k].se){
        //         ans+=(s[i].fi + m[j].fi + b[k].fi);
        //         break;
        //     }
        //     else{
        //         if(s[i].se==m[j].se && s[i].se==b[k].se){
        //             ans+=max({s[i].fi,m[j].fi,b[k].fi});


        //         }
        //     }
        // }
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                    if(s[i].se!=m[j].se && s[i].se!=b[k].se && m[j].se!=b[k].se)
                        ans=max(ans,s[i].fi + m[j].fi + b[k].fi);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}