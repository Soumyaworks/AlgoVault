#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        map<char,int>m;
        string str;
        int n,flag=0;
        cin>>n;
        
        cin>>str;
        int i=0;
        while(i<n)
        {
            m[str[i]]++;
            i++;
        }
        for(auto itr:m)
        {
            if(itr.second%2!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        
    }
    return 0;
}