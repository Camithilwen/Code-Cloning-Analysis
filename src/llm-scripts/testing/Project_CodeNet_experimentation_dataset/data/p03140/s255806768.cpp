#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,su=0;
    string a,s,d;
    cin>>n>>a>>s>>d;
    set<char>se;
    for(i=0;i<n;i++)
    {
        se.insert(a[i]);
        se.insert(s[i]);
        se.insert(d[i]);
        su+=se.size()-1;
        se.clear();
    }
    cout<<su<<endl;
}
