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

ll fact(ll n){
    ll i,f=1;
    for(i=2;i<=n;i++){
        f=(f*i)%mod;
    }
    return f;
}
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
    ll t,i,j,k,n;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<vector<ll>>v(n);
        //vector<pair<ll,ll>>d(n);
        //unordered_map<ll,ll>mymap;
        ll x,y;
        for(i=0;i<n-1;i++){
            cin>>x>>y;
            x--;
            y--;
            v[x].pb(y);
            v[y].pb(x);
            //d[x]++;
            //d[y]++;
            //mymap[x]++;
            //mymap[y]++;
        }
        /*
        cout<<"The graph"<<"\n";
        for(i=0;i<n;i++){
            for(j=0;j<v[i].size();j++)
            cout<<v[i][j];
            cout<<"\n";
        }
        */
        vector<pair<ll,ll>>ans(n);
        for(i=0;i<n;i++){
            vector<ll>level(n,0);
            vector<bool>visited(n,false);
            queue<ll>Q;
            visited[i]=true;
            Q.push(i);
            level[i]=0;
            //cout<<"Sequence:"<<"\n";
            while(!Q.empty()){
                ll x=Q.front();
                //cout<<x<<" ";
                Q.pop();
                for(ll u:v[x]){
                    if(!visited[u]){
                        visited[u]=true;
                        level[u]=level[x]+1;
                        Q.push(u);
                    }
                }
            }
            //cout<<"\n";
            
            set<ll>S;
            for(j=0;j<n;j++)
            S.insert(level[j]);
            vector<ll>nodes(S.size(),0);
            //cout<<"Print S:"<<"\n";
            for(auto it:S){
                //cout<<it<<" ";
                for(j=0;j<n;j++){
                    if(level[j]==it)
                    nodes[it]++;
                }
            }
            //cout<<"\n";
            
            ll p=1;
            //cout<<"i="<<i<<"\n";
            //cout<<"Nodes:"<<"\n";
            for(j=0;j<nodes.size();j++){
                //cout<<nodes[j]<<" ";
                p=(p*fact(nodes[j]))%mod;
            }
            //cout<<"\n";
            ans[i].fi=p;
            ans[i].se=i+1;
            
        }
        
        sort(ans.rbegin(),ans.rend());
        cout<<"Answer:"<<"\n";
        for(auto it:ans)
        cout<<it.fi<<" "<<it.se<<"\n";
        if(k==1)
        cout<<ans[0].se<<" "<<ans[0].fi<<"\n";
        else if(k==2)
        cout<<ans[1].se<<" "<<ans[1].fi<<"\n";
        
    }
    return 0;
}