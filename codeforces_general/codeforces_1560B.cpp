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
    ll t,a,b,c,i,j,k;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        ll min1=min(a,b);
        ll max1=max(a,b);
        if(min1-1>(max1-min1-1))
        cout<<-1<<"\n";
        else{
            if(c==min1)
            cout<<max1<<"\n";
            else if(c==max1)
            cout<<min1<<"\n";
            else{
            if(c>=1 && c<min1){
                ll p=c-1;
                if(max1-p<min1)
                cout<<-1<<"\n";
                else
                cout<<max1-p<<"\n";
            }
            else if(c>min1 && c<max1){
                ll p=c-min1;
                ll d=max1-min1-1;
                if(p>d/2)
                cout<<min1-p+1<<"\n";
                else
                cout<<max1+p<<"\n";
            }
            else{
                ll p=c-max1;
                if((max1-min1)<p)
                cout<<-1<<"\n";
                else
                cout<<min1+p<<"\n";
            }
            }
        }
    }
    return 0;
}