// Author : Soumya Banerjee
// "Great things are not done by impulse, but by a series of small things brought together." - Vincent Van Gogh
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

bool isPrime(int n) {
    if (n <= 1) return false;        // 0 and 1 are not prime
    if (n <= 3) return true;         // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false; // Eliminate multiples of 2 and 3
    
    // Check divisors from 5 to √n
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
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
        vector<int>even,odd;
        for(i=1;i<=n;i++){
            if(i%2==0) even.pb(i);
            else odd.pb(i);
        }
        vector<int>ans(n);
        i=0;
        for(auto x:even) ans[i++]=x;
        for(auto x:odd) ans[i++]=x;
        int flag=0;
        for(i=1;i<n;i++){
            if(ans[i-1]%2==0 && ans[i]%2==1){
                flag=1;
                break;
            }
        }
        if(flag==1){
            int sum = ans[i-1]+ans[i];
            if(!isPrime(sum)){
                for(auto x:ans) cout<<x<<" ";
                cout<<"\n";
            }
            else{
                j=i;
                i++;
                bool found=false;
                for(;i<n;i++){
                    int sum = ans[j-1]+ans[i];
                    if(!isPrime(sum)){
                        found=true;
                        swap(ans[j],ans[i]);
                        break;
                    }
                }
                if(found){
                    for(auto x:ans) cout<<x<<" ";
                    cout<<"\n";
                }
                else
                    cout<<-1<<"\n";
            }
        }
        else{
            cout<<-1<<"\n";
        }
    }
    return 0;
}