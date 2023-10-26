#include <bits/stdc++.h>
using namespace std;

//Reference taken from https://www.tutorialspoint.com/bitwise-ors-of-subarrays-in-cplusplus

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        vector <long long int> ar(n);
        long i,j;
        set <long> s1;
        long l=(n*(n+1))/2;
        for(i=0;i<n;i++)
        {
            cin>>j;
            ar.push_back(j);
            s1.insert(j);
        }
        
        unordered_set <long long int> ret;
        unordered_set <long long int> c2;
        for(i=0;i<ar.size();i++)
        {
            unordered_set <long long int> c1;
            c1.insert(ar[i]);
            unordered_set<long long int>::iterator itr = c2.begin();
            while(itr!=c2.end())
            {
                c1.insert(*itr | ar[i]);
                itr++;
            }
            itr=c1.begin();
            while(itr!=c1.end())
            {
                ret.insert(*itr);
                itr++;
            }
            c2=c1;
            c1.clear();
        }
        if(ret.size()!=l)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
        ret.clear();
        c2.clear();
        
    }
return 0;
}

   