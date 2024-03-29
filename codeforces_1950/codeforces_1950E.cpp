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


vector<int> computePrefixFunction(string& s) {
    int n = s.length();
    vector<int> prefix(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = prefix[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = prefix[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        prefix[i] = j;
    }
    return prefix;
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
        int i,j,k,n,ans=0;
        cin>>n;
        string s;
        cin>>s;
        // ans=n;
        // unordered_map<char,int>mymap;
        // for(auto it:s)
        //     mymap[it]++;
        // vector<int>v;
        // for(auto it:mymap)
        //     v.pb(it.se);
        // sort(v.begin(),v.end());
        // if(v.size()==1)
        //     cout<<1<<"\n";
        // else{
        //     if(v[0]!=1)
        //         cout<<n<<"\n";
        //     else{
        //         v[1]++;
        //         if(v.size()==2)
        //             cout<<1<<"\n";
        //         else{
        //             int flag=0;
        //             for(i=2;i<v.size();i++){
        //                 if(v[i]==v[i-1] || v[i]%v[1]==0)
        //                     continue;
        //                 else{
        //                     flag=1;
        //                     break;
        //                 }
        //             }
        //             if(flag==1)
        //                 cout<<n<<"\n";
        //             else
        //                 cout<<v.size()<<"\n";
        //         }
                

        //     }
        // }
        // cout<<ans<<"\n";
        for(int i = 1; i <= n; i++)
        {
            if(n%i == 0)
            {
                int satisfy = 2;
                for(int j = 0; j < i; j++)
                {
                    for(int k = j+i; k < n; k+=i)
                    {
                        if(s[k] != s[j])
                        {
                            satisfy--;
                        }
                    }
                }
                if(satisfy > 0)
                {
                    cout << i << endl;
                    // return;
                    break;
                }
                satisfy = 2;
                for(int j = n-i; j < n; j++)
                {
                    for(int k = j-i; k >= 0; k-=i)
                    {
                        if(s[k] != s[j])
                        {
                            satisfy--;
                        }
                    }
                }
                if(satisfy > 0)
                {
                    cout << i << endl;
                    // return;
                    break;
                }
            }
        }
    }
    return 0;
}