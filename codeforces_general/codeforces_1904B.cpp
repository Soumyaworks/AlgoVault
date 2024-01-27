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
        ll n,i,j,k;
        cin>>n;
        vector<pair<ll,ll>>a(n);
        for(i=0;i<n;i++){
            cin>>a[i].fi;
            a[i].se=i;
        }
        sort(a.begin(),a.end());
        vector<ll>temp(n);
        for(i=0;i<n;i++){
            temp[i]=a[i].fi;
        }
        for(i=0;i<n;i++){
            if(i==0)
                continue;
            else{
                a[i].fi+=a[i-1].fi;
            }
        }
        
        // for(auto it:a){
        //     cout<<it.fi<<" "<<it.se<<endl;
        // }
        vector<ll>ans(n);
        for(i=0;i<n;i++){
            k=-1;
            ll p=a[i].fi;
            ll x=-2;
            while(true){
                auto it=upper_bound(temp.begin(),temp.end(),p);
                if(it!=temp.end()){
                    k=distance(temp.begin(),it);
                    // if(temp[k]>a[i].fi)
                    k--;
                    if(x==k)
                        break;
                    p=a[k].fi;
                    // cout<<"k="<<k<<endl;
                    x=k;
                }
                else{
                    k=n-1;
                    break;
                }
            }
            // else
            //     k=n-1;
            k=(k!=-1)?(k-i):0;
            k+=i;
            ans[a[i].se]=k;
        }
        for(i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}