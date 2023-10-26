//Author : Soumya Banerjee
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("Ofast")
#define ll long long int
#define pb push_back
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
    /*
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    */
    //cout<<"Hello World"<<"\n";
    ll t,n,k,i,j,c;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<ll>a(n);
        unordered_map<int,pair<int,int>>M;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(M[a[i]].fi>0){
                j=M[a[i]].fi;
                M[a[i]].fi=i+1;
                M[a[i]].se=j;
            }
            else{
                M[a[i]].fi=i+1;
                M[a[i]].se=-1;
            }

        }
        c=LLONG_MIN;
        /*
        for(i=n-1;i>=0;i--){
            j=i+1;
            if((j-1)>=1){
                c=max(c,(j*(j-1)-k*(a[j-1]|a[(j-1)])));
            }
            if((j-2)>=1){
                c=max(c,(j*(j-1)-k*(a[j-1]|a[(j-2)])));
            }
        }
        if(n==2)
        c=2-k*(a[0]|a[1]);
        */
        sort(a.begin(),a.end());
        for(i=1;i<n;i++){
            ll temp=k*(a[i]|a[i-1]);
            ll p;
            if(a[i]!=a[i-1])
            {
                p=M[a[i]].fi*M[a[i-1]].fi;

            }
            else{
                p=M[a[i]].fi*M[a[i]].se;
            }
            c=max(c,p-temp);
            if(i-2>=0){
                temp=k*(a[i]|a[i-2]);
                p;
                if(a[i]!=a[i-2])
                {
                    p=M[a[i]].fi*M[a[i-2]].fi;

                }
                else{
                    p=M[a[i]].fi*M[a[i]].se;
                }
                c=max(c,p-temp);
            }
        }
        
        cout<<c<<"\n";
    }
    return 0;
}