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

struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
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
        cin>>n;
        vector<pair<int,int>>a(n);
        vector<int>ans(n);
        for(i=0;i<n;i++){
            cin>>a[i].fi>>a[i].se;
        }
        sort(a.begin(),a.end(),sort_pred());
        int min1=-1,min2=-1,max1=-1,max2=-1;
        bool not_possible = false;
        for(i=0;i<n;i++){
            if(min1==-1 && max1==-1){
                min1=a[i].fi;
                max1=a[i].se;
                ans[i]=1;
            }
            else{
                int x = a[i].fi;
                int y = a[i].se;
                if(x<=max1 && x<=max2){
                    not_possible = true;
                    break;
                }
                if(x<=max1){
                    max1=y;
                    ans[i]=1;
                }
                else{
                    if(min2==-1 && max2==-1){
                        min2=x;
                        max2=y;
                        ans[i]=2;
                    }
                    else{
                        if(x<=max1 && x<=max2){
                            not_possible = true;
                            break;
                        }
                        else{
                            max2=y;
                            ans[i]=2;
                        }
                    }                    
                }
            }
            // cout<<"1st set : "<<min1<<","<<max1<<"\n";
            // cout<<"2nd set : "<<min2<<","<<max2<<"\n";
        }
        if(not_possible)
            cout<<-1<<"\n";
        else if(min2==-1)
            cout<<-1<<"\n";
        else{
            for(auto x:ans)
                cout<<x<<" ";
            cout<<"\n";
        }
    }
    return 0;
}