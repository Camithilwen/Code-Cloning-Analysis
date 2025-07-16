#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
int main()
{
    ll n;
    cin>>n;
    ll m=n,sum=0;
    while(m>0)
    {
        sum+=m%10;
        m=m/10;
    }
  //  cout<<sum<<endl;
    if(n%sum==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
