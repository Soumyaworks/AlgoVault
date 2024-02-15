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


bool isPossible(std::vector<ll> a) {
  int n = a.size();
  int total = 0;
  for (int i : a) {
    total += i;
  }

  // Check if the sum is divisible by n
  if (total % n != 0) {
    return false;
  }

  // Calculate the target amount after equal distribution
  int target = total / n;

  // For each container, calculate the difference between its content and the target
  std::vector<int> diff(n);
  for (int i = 0; i < n; ++i) {
    diff[i] = a[i] - target;
  }

  // Check if we can eliminate all positive differences by only pouring water to the right
  int prefix_sum = 0;
  for (int i = 0; i < n; ++i) {
    prefix_sum += diff[i];
    if (prefix_sum < 0) {
      // We cannot pour enough water to the right from previous containers
      return false;
    }
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
    ll t;
    cin>>t;
    while(t--){
        ll n,i,j,k,s=0,p;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }
        // ll l=0,h=n-1;
        // k=s/n;
        // i=0;
        // ll f=0;
        // while(l<h){
        //     if(a[l]==k){
        //         l++;
        //         i++;
        //         continue;
        //     }
        //     if(a[h]==k){
        //         h--;
        //         i++;
        //         continue;
        //     }
        //     // if(a[l]<a[h]){
        //     //     f=1;
        //     //     break;
        //     // }
            
        //     j=a[l]-k;
        //     p=k-a[h];
        //     a[h]+=min(p,j);
        //     a[l]-=min(p,j);
        //     if(a[h]==k){
        //         h--;
        //         i++;
        //     }
        //     if(a[l]==k){
        //         l++;
        //         i++;
        //     }
        // }
        // if(i==n || n==1){
        //     cout<<"YES"<<"\n";
        // }
        // else
        //     cout<<"NO"<<"\n";
        if(isPossible(a))
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }
    return 0;
}