
#include<bits/stdc++.h>
using namespace std;
int main()
{int n;
string s;
cin>>n;
cin>>s;
if(s.size()>n)
{
    s.erase(n);
    cout<<s+"..."<<endl;}
    else cout<<s<<endl;
    return 0;
}
