#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("Ofast")
#define ll int
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
    ll t,i,j,k,f,c,f1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>p(n),q(n),m(n);
        for(i=0;i<n;i++){
            cin>>p[i];
            //q[i]=p[i];
        }
        //sort(q.rbegin(),q.rend());
        k=0;f=n;f1=0;
        j=n-1;
        while(k<n){
            f1=j;
        for(i=j;i>=0;i--){
            if(p[i]==f)
            {
                //m[k++]=p[i];
                j=i-1;
                f--;
                break;
            }
           
        }
        if(i==-1)
        f--;
        else{
            for(i=j+1;i<=f1;i++){
                if(p[i]==f)
                f--;
                m[k++]=p[i];
            }
        }
        }
        for(i=0;i<n;i++)
        cout<<m[i]<<" ";
        cout<<"\n";
    }
    return 0;
}