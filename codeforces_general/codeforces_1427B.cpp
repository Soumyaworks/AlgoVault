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
        int i,j,k,n;
        cin>>n>>k;
        string s;
        cin>>s;
        s+='L';
        int ans=0;
        vector<int>pos,pre(n);
        for(i=0;i<n;i++){
            if(s[i]=='L'){
                pos.pb(i);
                if(i==0)
                    pre[i]=0;
                else
                    pre[i]=pre[i-1];
            }                
            else{
                if(i==0 || (i>0 && s[i-1]=='L'))
                    ans+=1;
                else 
                    ans+=2;
                pre[i]=ans;
            }
        }
        // cout<<"ans till this point, ans and pre[n-1] should be same: "<<ans<<"," << pre[n-1] <<"\n";
        if(pos.empty() || k==0)
            cout<<ans<<"\n";
        else{
            int sum=0;
            for(i=0;i<pos.size()-1;i++){
                sum=0;
                j=i+k;
                j=min(j, (int)pos.size()-1);
                if(pos[i]==0 || (pos[i]>0 && s[pos[i]-1]=='L')){
                    if(j==(int)pos.size()-1)
                        sum+= (pos[j]-pos[i])*2+1;
                    else
                        sum+= (pos[j]-pos[i]-1)*2+1;
                    if(pos[i]>0)
                        sum+=pre[pos[i]-1];
                    if(pos[j]>0)
                        sum+= (pre[pos[j]] - pre[pos[j]-1]);
                }
                else{
                    sum+= (pos[j]-pos[i])*2;
                    if(pos[i]>0)
                        sum+=pre[pos[i]-1];
                    if(pos[j]>0)
                        sum+= (pre[n-1] - pre[pos[j]-1]);
                }
                // cout<<"sum coming over here; " << sum<<"\n";
                ans=max(ans,sum);
            }
            cout<<ans<<"\n";
        }
        
    }
    return 0;
}