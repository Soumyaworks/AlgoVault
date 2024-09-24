// Author: Soumya Banerjee
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        ll i,j,k,n,m,ans=-1;
        unordered_map<ll,ll>cnt;
        cin>>n>>m;
        for(i=0;i<m;i++){
            cin>>k;
            k--;
            cnt[k]++;
        }
        ll low = 1, high = 2*m;
        while(low<=high){
            ll mid = low + (high - low)/2;
            bool can_do = false;
            ll left = 0, help = 0;
            for(i=0;i<n;i++){
                if(mid>cnt[i]){
                    help += (mid-cnt[i])/2;
                }
                else
                    left += cnt[i]-mid;
            }
            can_do = (left<=help);
            if(can_do){
                ans = mid;
                high = mid-1;
            }
            else    
                low = mid+1;            
        }
        cout<<ans<<"\n";
    }
    
}