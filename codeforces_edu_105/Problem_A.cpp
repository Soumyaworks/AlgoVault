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
    int t,n,i,j,k;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n=s.length();
        if(s[0]==s[n-1])
        cout<<"NO"<<"\n";
        else{
            int a[3]={-1,-1,-1};
            int x=(int)s[0]-65;
            int y=(int)s[n-1]-65;
            a[((int)s[0]-65)]=1;
            a[((int)s[n-1]-65)]=-1;
            int c=0;
            k=0;
            int z;
            for(i=0;i<n;i++){
                if(((int)s[i]-65)!=x && ((int)s[i]-65)!=y){
                    c++;
                    k--;
                    z=(int)s[i]-65;
                }
                else{
                    c+=a[((int)s[i]-65)];
                    k+=a[((int)s[i]-65)];
                }
            }
            if(c==0){
                a[z]=1;
                int p=0;
                int open=0,closed=0;
                for(i=0;i<n;i++){
                    j=(int)s[i]-65;
                    if(a[j]==1)
                    open++;
                    else
                    closed++;
                    if(open<closed){
                        p=1;
                        break;
                    }
                }
                if(p==1)
                cout<<"NO"<<"\n";
                else
                cout<<"YES"<<"\n";
            }
            else if(k==0){
                a[z]=-1;
                int p=0;
                int open=0,closed=0;
                for(i=0;i<n;i++){
                    j=(int)s[i]-65;
                    if(a[j]==1)
                    open++;
                    else
                    closed++;
                    if(open<closed){
                        p=1;
                        break;
                    }
                }
                if(p==1)
                cout<<"NO"<<"\n";
                else
                cout<<"YES"<<"\n";
            }
            else
            cout<<"NO"<<"\n";
            
        }
    }
    return 0;
}