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
    int t,x,y,i,j,k;
    cin>>t;
    int z;
    for(z=1;z<=t;z++){
        cin>>x>>y;
        string s;
        cin>>s;
        int n=0;
        for(i=0;i<s.length();i++){
            if(s[i]=='?')
            n++;
        }
        int c=INT_MAX;
        string h;
        for(i=1;i<=n;i++)
        h+='C';
        for(int b=0;b<(1<<n);b++){
            string str=h;
            for(i=0;i<n;i++){
                if(b&(1<<i))
                str[i]='J';
            }
            string s1=s;
            k=0;
            for(i=0;i<s1.length();i++){
                if(s1[i]=='?'){
                    s1[i]=str[k++];
                }
            }
            int pr=0;
            for(int f=0;f<s1.length();f++){
                if(s1[f]=='?')
                s1[f]=str[k++];
            }
            //cout<<"New String="<<s1<<"\n";
            for(int f=1;f<s1.length();f++){
                if(s1[f]=='J' && s1[f-1]=='C')
                pr+=x;
                else if(s1[f]=='C' && s1[f-1]=='J')
                pr+=y;
            }
            c=min(c,pr);

        }
        if(c==INT_MAX)
        cout<<"Case #"<<z<<": "<<0<<"\n";
        else
        cout<<"Case #"<<z<<": "<<c<<"\n";
    }
    return 0;
}