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

vector<int> gotonearest(vector<int>v,int n,int x){
    int i,j,k;
    for(i=n+1;i<=x;i++){
        for(j=0;j<=((int)log2(x)+1);j++){
            if((x&(1<<j))==0){
                v[j]++;
            }
        }
    }
    return v;
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
        int i,j,k,l,r;
        cin>>l>>r;
        vector<int>v1(log2(r)+1),v2(log2(r)+1);
        int nr=(int)pow(2,log2(r));
        int nl=(int)pow(2,log2(l));
        int n=log2(r)+1;
        cout<<"n="<<n<<" nr="<<nr<<" nl="<<nl<<"\n";
        j=0;
        for(i=n-1;i>=0;i--){
            cout<<"((nr/(int)pow(2,j+1))*(j+1)) = "<<((nr/(int)pow(2,j))*(j))<<"\n";
            v2[i]=(nr)-((nr/(int)pow(2,j))*(j));
            j++;
        }
        j=0;
        for(i=n-1;i>=0;i--){
            cout<<"((nl/(int)pow(2,j+1))*(j+1)) = "<<((nl/(int)pow(2,j))*(j))<<"\n";
            v1[i]=(nl)-((nl/(int)pow(2,j))*(j));
            j++;
        }
        cout<<"before goto\n";
        for(auto it :v1){
            cout<<it<<" ";
        }
        cout<<"\n";
        for(auto it :v2){
            cout<<it<<" ";
        }
        cout<<"\n";
        v1=gotonearest(v1,nl,l-1);
        v2=gotonearest(v2,nr,r);
        cout<<"after goto\n";
        for(auto it :v1){
            cout<<it<<" ";
        }
        cout<<"\n";
        for(auto it :v2){
            cout<<it<<" ";
        }
        cout<<"\n";
        int ans=INT_MAX;
        for(i=n-1;i>=0;i--){
            v2[i]-=v1[i];
            ans=min(ans,v2[i]);
        }
        for(auto it :v2){
            cout<<it<<" ";
        }
        cout<<"\n";
        cout<<ans<<"\n";

    }
    return 0;
}