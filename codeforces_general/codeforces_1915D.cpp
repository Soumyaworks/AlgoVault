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

bool vow(char ch){
    if(ch=='a' || ch=='e')
        return true;
    return false;
}
bool cons(char ch){
    if(ch=='b' || ch=='c' || ch=='d')
        return true;
    return false;
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
        string ans="";
        cin>>s;
        if(n<=3){
            cout<<s<<"\n";
            continue;
        }
        unordered_set<int>S;
        for(i=0;i<s.size()-1;){
            if((i+2)<s.size() && (i+3)<s.size() && (cons(s[i+2]) && cons(s[i+3]))){
                // s=s.substr(0,i+3)+"."+s.substr(i+3);
                S.insert(i+2);
                i+=3;
            }
            else if((i+2)<s.size() && (i+3)>=s.size())
                i+=3;
            else{
                // s=s.substr(0,i+2)+"."+s.substr(i+2);
                S.insert(i+1);
                i+=2;
            }
        }
        // for(auto it:S){
        //     cout<<"it="<<it<<"\n";
        // }
        // cout<<"originl string ="<<s<<"\n";
        for(i=0;i<n;i++){
            if(S.find(i)!=S.end()){
                ans+=s[i];
                ans+='.';
            }
            else    
                ans+=s[i];
        }
        if(ans[ans.size()-1]=='.')
            ans.pop_back();
        cout<<ans<<"\n";

    }
    return 0;
}