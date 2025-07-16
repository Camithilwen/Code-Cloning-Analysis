#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<long long >v;
    vector<long long >t;
    vector<long long >f;
    set<long long>s;
    set<long long>::iterator it;
    map<long long,long long>m;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        m[x]+=1;
       s.insert(x);
    }
    long long mx=0;
    for(it=s.begin();it!=s.end();it++)
    {
        if(m[*it]>=2)
        {
            t.push_back(*it);
        }
        if(m[*it]>=4)
        {
            f.push_back(*it);
        }
    }
    if(f.size()!=0)
    {
       mx=max(mx,f[f.size()-1]*f[f.size()-1]);
    }
     if(t.size()>=2)
    {
         mx=max(mx,t[t.size()-1]*t[t.size()-2]);
    }


cout<<mx<<endl;

}
