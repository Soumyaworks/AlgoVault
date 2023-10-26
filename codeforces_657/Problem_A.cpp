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

int countFreq(string pat, string txt) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 
    int res = 0; 
    
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) 
    {  
        /* For current index i, check for  
           pattern match */
        int j; 
        for (j = 0; j < M; j++) 
            if (txt[i+j] != pat[j]) 
                break; 
   
        // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
        if (j == M)   
        { 
           res++; 
           j = 0; 
        } 
    } 
    return res; 
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
    int t,n,i,j,k,c,p;
    cin>>t;
    string str;
    str="abacaba";
    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;
        if(n<7)
        cout<<"NO"<<"\n";

        else
        {
            if(s.find("abacaba")!=string::npos && countFreq(s,str)==1)
            {
                cout<<"YES"<<"\n";
                for(i=0;i<n;i++)
                {
                    if(s[i]=='?')
                    cout<<'x';
                    else
                    {
                        cout<<s[i];
                    }
                    
                }
                cout<<"\n";
            }
            else if(s.find("?")==string::npos)
            {
                cout<<"NO"<<"\n";
            }
            else
            {
                int f=0;
                for(i=0;i<n;i++)
                {
                    if(s[i]=='?')
                    s[i]='x';
                }
                for(i=0;i<n;i++)
                {
                    if((s[i]=='a' && (i+6)<n && f!=1) || (s[i]=='x' && (i+6)<n && f!=1))
                    {
                        for(j=i;j<(i+7);j++)
                        {
                            if(s[j]!='x' && s[j]!=str[j-i])
                            break;
                            
                        }
                        if(j==(i+7))
                        {
                            for(j=i;j<(i+7);j++)
                            {
                                if(s[j]=='x')
                                s[j]=str[j-i];
                            }
                            cout<<"Changed string:"<<s<<"\n";
                            f=1;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                        

                    }
                }
                if(f==1 && countFreq(s,str)==1)
                {
                    cout<<"YES"<<"\n";
                    cout<<s<<"\n";
                }
                else
                {
                    cout<<"NO"<<"\n";
                }
                
            }
            
        }
        
    }
    return 0;
}