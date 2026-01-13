// Author : Soumya Banerjee
// "Great things are not done by impulse, but by a series of small things brought together." - Vincent Van Gogh

// Question:

// Let's denote the f(x)
//  function for a string x
//  as the number of distinct characters that the string contains. For example f(abc)=3
// , f(bbbbb)=1
// , and f(babacaba)=3
// .

// Given a string s
// , split it into two non-empty strings a
//  and b
//  such that f(a)+f(b)
//  is the maximum possible. In other words, find the maximum possible value of f(a)+f(b)
//  such that a+b=s
//  (the concatenation of string a
//  and string b
//  is equal to string s
// ).

// Input
// The input consists of multiple test cases. The first line contains an integer t
//  (1≤t≤104
// ) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains an integer n
//  (2≤n≤2⋅105
// ) — the length of the string s
// .

// The second line contains the string s
// , consisting of lowercase English letters.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output a single integer  — the maximum possible value of f(a)+f(b)
//  such that a+b=s
// .

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
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<char,int>mymap;
        int distinct=0;
        for(auto x:s){
            distinct+= (mymap[x]==0);
            mymap[x]++;
        }
        int left=0,right=distinct;
        unordered_set<char>S;
        int ans=0;
        for(int i=0;i<n;i++){
            if(S.count(s[i])==0){
                S.insert(s[i]);
            }
            mymap[s[i]]--;
            if(mymap[s[i]]==0){
                right--;                
            }
            ans=max(ans,(int)S.size()+right);
        }
        cout<<ans<<"\n";
    }
    return 0;
}