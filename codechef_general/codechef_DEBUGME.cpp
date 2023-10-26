#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007

int main() {
    FIO;
    int t, n, k, i, j, x, cnt1, cnt2, tmp,p;
    string s;

    cin >> t;
    while (t--> 0) {
        cin >> n >> k;
        cin >> s;

        int disparity[n][n];
        int frequency[26] = {0};

        for (i = 0; i < n; i++) {
            
            for (j = i; j < n; j++) {
                if(i==0)
                frequency[(int)s[j] - 97]++;
                cnt1 = 0;
                cnt2 = INT_MAX;
                for (p = 0; p <= 25; p++) {
                    cnt1 = max(cnt1, frequency[p]);
                    if (frequency[p] > 0)
                        cnt2 = min(cnt2, frequency[p]);
                }

                for (p = 0; p <= 25; p++)
                    if (frequency[p] == cnt1)
                        break;

                disparity[i][j] = p;

                for (p = 0; p <= 25; p++)
                    if (frequency[p] == cnt2)
                        break;

                disparity[i][j] =abs(disparity[i][j]-p);
            }
        }
        cout<<"frequency table:"<<"\n";
        for(i=0;i<26;i++)
        {
            cout<<"freq of"<<(char)(97+i)<<"= "<<frequency[i]<<"\n";
        }
        cout<<"\n";
        cout<<"disparity table:"<<"\n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            cout<<disparity[i][j]<<" ";
            cout<<"\n";
        }
        int dp[k][n];

        for (i = 0; i < n; i++) {
            dp[0][i] = disparity[0][i];
        }

        for (i = 1; i < k; i++) {
            for (j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j];
                for (x = 0; x < j; x++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][x] + disparity[x + 1][j]);
                }
            }
        }

        cout << dp[k - 1][n - 1] << "\n";
    }
    return 0;
}
