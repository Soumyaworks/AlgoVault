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
        int a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        int suneetWins = 0;
        
        int suneetScore, slavicScore;
        
        // (a1 vs b1) and (a2 vs b2)
        suneetScore = (a1 > b1) + (a2 > b2);
        slavicScore = (b1 > a1) + (b2 > a2);
        if (suneetScore > slavicScore) suneetWins++;
        
        // (a1 vs b2) and (a2 vs b1)
        suneetScore = (a1 > b2) + (a2 > b1);
        slavicScore = (b2 > a1) + (b1 > a2);
        if (suneetScore > slavicScore) suneetWins++;
        
        // (a2 vs b1) and (a1 vs b2)
        suneetScore = (a2 > b1) + (a1 > b2);
        slavicScore = (b1 > a2) + (b2 > a1);
        if (suneetScore > slavicScore) suneetWins++;
        
        // (a2 vs b2) and (a1 vs b1)
        suneetScore = (a2 > b2) + (a1 > b1);
        slavicScore = (b2 > a2) + (b1 > a1);
        if (suneetScore > slavicScore) suneetWins++;
        
        cout << suneetWins << "\n";
    }
    return 0;
}