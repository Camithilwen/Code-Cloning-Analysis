#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,tem;
    cin>>n;
    vector<long int>p;
    for(long int i=0;i<n;i++)
    {
        cin>>tem;
        p.push_back(tem);
    }
    long int c=1,mini=p[0];
     for(long int i=1;i<n;i++)
    {
       if(mini>=p[i])
       {
           c++;
           mini=p[i];
       }
    }
    cout<<c<<"\n";
return 0;}
