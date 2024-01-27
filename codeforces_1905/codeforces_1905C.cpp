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

string lex_largest_subseq(string s,vector<int>&a){ // in our code, index required, hence vector<int>a used, else not needed
    // vector<int>a;
    string str="";
    int i,n=s.size();
    for(i=n-1;i>=0;i--){
        if(a.empty() || s[i]>=s[a.back()]){
            str+=s[i];
            a.pb(i);
        }
    }
    reverse(str.begin(),str.end());
    reverse(a.begin(),a.end());
    return str;
}

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
        string s;
        cin>>s;
        vector<int>a;
        string str=lex_largest_subseq(s,a);
        // cout<<str<<"\n";
        j=0;
        while(j<a.size() && s[a[0]]==s[a[j]]){
            j++;
        }
        int ans=a.size()-j;
        int sz=a.size();
        for(i=0;i<sz/2;i++){
            swap(s[a[i]],s[a[sz-i-1]]);
        }
        cout<<((is_sorted(s.begin(),s.end()))?ans:-1)<<"\n";
    }
    return 0;
}