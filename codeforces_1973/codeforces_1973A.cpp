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
        int i,j,p1,p2,p3;
        cin>>p1>>p2>>p3;
        int ans=-1;
        if(p1==0 && p2==0 && p3==0)
            ans=0;
        else if((p1+p2+p3)%2)
            ans=-1;
        else{
            priority_queue<int>pq;
            ans=0;
            pq.push(p1);
            pq.push(p2);
            pq.push(p3);
            while(!pq.empty()){
                int first = pq.top();
                pq.pop();
                if(!pq.empty()){
                    int second = pq.top();
                    pq.pop();
                    if(first>0 && second>0){
                        ans++;
                        first--;
                        second--;
                        if(first>0)
                            pq.push(first);
                        if(second>0)
                            pq.push(second);
                    }
                    else
                        break;
                }
                else  
                    break;
            }            
        }
        cout<<ans<<"\n";
    }
    return 0;
}