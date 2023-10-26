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
    ll t,i,j,k,p,a,b,c;
    cin>>t;
    while(t--){
        cin>>p>>a>>b>>c;
        ll d1,d2,d3;
        if(p<=a)
        d1=abs(p-a);
        else{
            k=p/a;
            if(p%a!=0)
            a=(k+1)*a;
            else
            a=k*a;
            d1=abs(p-a);
        }

        if(p<=b)
        d2=abs(p-b);
        else{
            k=p/b;
            if(p%b!=0)
            b=(k+1)*b;
            else
            b=k*b;
            d2=abs(p-b);
        }

        if(p<=c)
        d3=abs(p-c);
        else{
            k=p/c;
            if(p%c!=0)
            c=(k+1)*c;
            else
            c=k*c;
            d3=abs(p-c);
        }

        ll d=min(d1,d2);
        d=min(d,d3);
        cout<<d<<"\n";

    }
    return 0;
}