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
    
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    
    //cout<<"Hello World"<<"\n";
    int t,i,j,k,c;
    cin>>t;
    for(int z=1;z<=t;z++){
        string s;
        cin>>s;
        int n=s.size();
        int max_vow=0,max_cons=0,count_vow=0,count_cons=0;
        unordered_map<char,int>M;
        for(i=0;i<n;i++)
        M[s[i]]++;
        unordered_set<char>S;
        S.insert('A');
        S.insert('E');
        S.insert('I');
        S.insert('O');
        S.insert('U');
        char max_v='a',max_c='a';
        for(auto it:M){
            //cout<<"it.first="<<it.first<<" it.second="<<it.second<<"\n";
            if(S.find(it.first)!=S.end()){
                count_vow+=it.second;
                //max_vow=max(max_vow,it.second);
                if(max_vow<it.second){
                    max_vow=it.second;
                    max_v=it.first;
                }
            }
            else{
                count_cons+=it.second;
                //max_cons=max(max_cons,it.second);
                if(max_cons<it.second){
                    max_cons=it.second;
                    max_c=it.first;
                }
            }
        }
        //cout<<"max_vow="<<max_vow<<" max_cons="<<max_cons<<"\n";
        //cout<<"max_c="<<max_c<<" max_v="<<max_v<<"\n";
        int ans=0,t1=0,t2=0,t3=0,t4=0;
        for(i=0;i<n;i++){
            if(S.find(s[i])==S.end()){
                if(s[i]!=max_c)
                t1+=2;
                //t2++;
            }
            else{
                if(s[i]!=max_v)
                t3+=2;
                //t4++;
            }
        }
        if(n==1 || max_vow==n || max_cons==n)
        cout<<"Case #"<<z<<": "<<0<<"\n";
        else{
            //cout<<"t1="<<t1<<" t3="<<t3<<"\n";
            if(max_c=='a')
            ans=min(n,t3);
            else if(max_v=='a')
            ans=min(n,t1);
            else
            ans=min(t1+count_vow,t3+count_cons);
            cout<<"Case #"<<z<<": "<<ans<<"\n";
        }
    }
    return 0;
}