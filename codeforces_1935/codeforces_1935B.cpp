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
        int i,j,k,n;
        cin>>n;
        vector<int>a(n);
        unordered_set<int>S,t;
        for(i=0;i<n;i++){
            cin>>a[i];
            S.insert(a[i]);
        }
        int mex=-1;
        for(i=0;i<=n;i++){
            if(S.count(i)==0){
                mex=i;
                break;
            }
        }
        // cout<<"mex = "<< mex<<"\n";
        if(mex==n){
            cout<<-1<<"\n";
        }
        else{
            k=-1;
            S.clear();
            for(i=0;i<mex;i++)
                S.insert(i);
            for(i=0;i<n;i++){
                if(S.count(a[i]))
                    t.insert(a[i]);
                if(t.size()==S.size()){
                    k=i;
                    break;
                }
            }
            t.clear();
            if(k!=-1){
                for(i=k+1;i<n;i++){
                    if(S.count(a[i]))
                        t.insert(a[i]);
                }
            }
            if(t.size()==S.size() && !t.empty() && k!=-1){
                cout<<2<<"\n";
                cout<<1<<" "<<k+1<<"\n";
                cout<<k+2<<" "<<n<<"\n";
            }
            else{
                if(mex==0){
                    cout<<2<<"\n";
                    cout<<1<<" "<<1<<"\n";
                    cout<<2<<" "<<n<<"\n";
                }
                else
                    cout<<-1<<"\n";
            }
        }
    }
    return 0;
}