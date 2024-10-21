// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,i,j,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll>a(n);
        for(auto &x:a) cin>>x;
        sort(a.begin(),a.end());
        ll winner=0;
        ll sub=0;
        for(auto x:a){
            x-=sub;
            if(x==1){
                winner^=1;
                sub+=x;
            }
            else if(x>1){
                winner^=1;
                break;
            }
        }
        if(winner)
            cout<<"Alice"<<"\n";
        else
            cout<<"Bob"<<"\n";
    }
    return 0;
}