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
    ll t;
    cin>>t;
    while(t--){
        ll n,m,i,j,k;
        cin>>n>>m;
        vector<ll>a(n),b(m),c(n);
        for(i=0;i<n;i++){
            cin>>a[i];
            // c[i]=a[i];
        }
        for(i=0;i<m;i++)
            cin>>b[i];
        sort(b.begin(),b.end());
        // c=a;
        sort(a.begin(),a.end());
        // sort(c.rbegin(),c.rend());
        ll ans1=0,ans2=0;
        for(i=0;i<n;i++){
            ans1+=abs(a[i]-b[m-1-i]);
        }
        for(i=0;i<n;i++){
            ans2+=abs(a[n-1-i]-b[i]);
        }
        // cout<<max(ans1,ans2)<<"\n";
        ll ans3=0;
        if(n%2==0){
            for(i=0;i<n/2;i++){
                ans3+=abs(a[i]-b[m-1-i]);
            }
            k=0;
            for(j=n-1;j>=(n/2);j--){
                ans3+=abs(a[j]-b[k++]);
            }
        }
        else{
            ll mid=n/2;
            for(i=0;i<n/2;i++){
                ans3+=abs(a[i]-b[m-1-i]);
            }
            k=0;
            for(j=n-1;j>(n/2);j--){
                ans3+=abs(a[j]-b[k++]);
            }
            ll p=max(abs(a[mid]-b[m-1-i]),abs(a[mid]-b[k]));
            cout<<b[m-1-i]<<" "<<b[k]<<"\n";
            ans3+=p;
        }
        ll ans4=0;
        ll p1=0,p2=n-1,p3=0,p4=m-1;;
        for(i=0;i<n;i++){
            if(abs(a[p1]-b[p4])>=abs(a[p2]-b[p3])){
                c[i]=abs(a[p1]-b[p4]);
                p1++;
                p4--;
            }
            else{
                c[i]=abs(a[p2]-b[p3]);
                p2--;
                p3++;
            }
            ans4+=c[i];
        }
        cout<<max({ans1,ans2,ans3,ans4})<<"\n";
    }
    return 0;
}