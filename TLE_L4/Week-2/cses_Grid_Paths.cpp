// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,k,p;
    cin>>n;
    vector<vector<char>>mat(n, vector<char>(n));
    vector<vector<int>>ans(n, vector<int>(n,0));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cin>>mat[i][j];
    }
    if(mat[0][0]=='*') ans[0][0]=0;
    else ans[0][0]=1;
    for(i=1;i<n;i++){
        if(mat[i][0]=='*')
            ans[i][0]=0;
        else 
            ans[i][0]=ans[i-1][0];
    }
    for(j=1;j<n;j++){
        if(mat[0][j]=='*')
            ans[0][j]=0;
        else    
            ans[0][j]=ans[0][j-1];
    }
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            if(mat[i][j]=='*')
                ans[i][j]=0;
            else
                ans[i][j]=(ans[i-1][j]+ans[i][j-1])%mod;
        }
    }
    cout<<ans[n-1][n-1];
    return 0;
}