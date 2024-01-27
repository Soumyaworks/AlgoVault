//Author : Soumya Banerjee
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("Ofast")
#define ll  int
#define pb push_back
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define mod 1000000007
#define fill(a,x) memset(a,x,sizeof(a))
#define indexed_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
using namespace __gnu_pbds;

// Defllion for a Linked List
struct ListNode {
    ll val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(ll x) : val(x), next(nullptr) {}
    ListNode(ll x, ListNode *next) : val(x), next(next) {}
    //ListNode *head=new ListNode();
    //ListNode *ptr1,*ptr2;
};

// Definition for a binary tree node.
struct TreeNode {
    ll val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    //TreeNode *root=new TreeNode();
};

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int maxVal;
    int minVal;
    int lazy;

    Node() : maxVal(0), minVal(0), lazy(0) {}
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    void pushLazy(int idx, int left, int right) {
        if (tree[idx].lazy != 0) {
            tree[idx].maxVal += tree[idx].lazy;
            tree[idx].minVal += tree[idx].lazy;
            if (left != right) {
                tree[2 * idx + 1].lazy += tree[idx].lazy;
                tree[2 * idx + 2].lazy += tree[idx].lazy;
            }
            tree[idx].lazy = 0;
        }
    }

    void update(int idx, int left, int right, int ql, int qr) {
        pushLazy(idx, left, right);

        if (left > qr || right < ql) return;
        
        if (ql <= left && right <= qr) {
            tree[idx].lazy++;
            pushLazy(idx, left, right);
            return;
        }

        int mid = (left + right) / 2;
        update(2 * idx + 1, left, mid, ql, qr);
        update(2 * idx + 2, mid + 1, right, ql, qr);

        tree[idx].maxVal = max(tree[2 * idx + 1].maxVal, tree[2 * idx + 2].maxVal);
        tree[idx].minVal = min(tree[2 * idx + 1].minVal, tree[2 * idx + 2].minVal);
    }

    int queryMax(int idx, int left, int right, int ql, int qr) {
        pushLazy(idx, left, right);

        if (left > qr || right < ql) return INT_MIN;
        
        if (ql <= left && right <= qr) {
            return tree[idx].maxVal;
        }

        int mid = (left + right) / 2;
        int leftMax = queryMax(2 * idx + 1, left, mid, ql, qr);
        int rightMax = queryMax(2 * idx + 2, mid + 1, right, ql, qr);

        return max(leftMax, rightMax);
    }

    int queryMin(int idx, int left, int right, int ql, int qr) {
        pushLazy(idx, left, right);

        if (left > qr || right < ql) return INT_MAX;
        
        if (ql <= left && right <= qr) {
            return tree[idx].minVal;
        }

        int mid = (left + right) / 2;
        int leftMin = queryMin(2 * idx + 1, left, mid, ql, qr);
        int rightMin = queryMin(2 * idx + 2, mid + 1, right, ql, qr);

        return min(leftMin, rightMin);
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void updateRange(int ql, int qr) {
        update(0, 0, n - 1, ql, qr);
    }

    int queryMax(int ql, int qr) {
        return queryMax(0, 0, n - 1, ql, qr);
    }

    int queryMin(int ql, int qr) {
        return queryMin(0, 0, n - 1, ql, qr);
    }
};

class FenwickTree {
private:
    vector<long long> tree;
    int size;

public:
    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }

    void update(int idx, long long delta) {
        for (; idx <= size; idx += idx & -idx) {
            tree[idx] += delta;
        }
    }

    void rangeUpdate(int left, int right, long long delta) {
        update(left, delta);
        update(right + 1, -delta);
    }

    long long query(int idx) {
        long long result = 0;
        for (; idx > 0; idx -= idx & -idx) {
            result += tree[idx];
        }
        return result;
    }

    long long rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
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
    int m,t,n,i,j,k;
    cin>>t;
    while(t--){
        cin>>n>>m;
        // SegmentTree segmentTree(m);
        FenwickTree fenwick(m);
        ll ans=0;
        for(i=1;i<=n;i++){
            int l,r;
            cin>>l>>r;
            // l--;
            // r--;
            fenwick.rangeUpdate(l, r, 1);
            // int maxVal=segmentTree.queryMax(0, n - 1);
            // int minVal=segmentTree.queryMin(0, n - 1);
            long long maxVal = fenwick.query(1);
            long long minVal = fenwick.query(1);
            if(maxVal-minVal > ans){
                ans=maxVal-minVal;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}