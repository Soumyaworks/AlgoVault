// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,i,j,k,p;
        cin>>n;
        int l=0;
        vector<int>a(n),ans;
        for(auto &x:a) cin>>x;
        if(n<=2){
            cout<<n<<"\n";
            for(auto x:a) cout<<x<<" ";
            cout<<"\n";
            continue;
        }
        int flag=0;
        if(a[0]<a[1]) flag=1;
        j=0;
        ans.push_back(a[0]);
        l++;
        for(i=2;i<n;i++){
           if((a[i]>a[i-1] && flag) || (a[i]<a[i-1] && !flag)){
                continue;
           }
           else{
                flag=!flag;
                ans.push_back(a[i-1]);
                // l-=(i-j-2);
                j=i-1;
                l++;
           }
        }
        ans.push_back(a[n-1]);
        l++;
        cout<<l<<"\n";
        for(auto x:ans){
            if(x!=-1) cout<<x<<" ";
        }
        cout<<"\n";

    }
    return 0;
}