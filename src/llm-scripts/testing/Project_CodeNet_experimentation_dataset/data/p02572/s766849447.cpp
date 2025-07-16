#include<bits/stdc++.h>
using namespace std;
const long mod=1e9+7;
long long sum,t;
int n;
long long a;
int main()
{
    cin>>n;
    while(n>0)
    {
        cin>>a;
        (sum+=a*t)%=mod;
        (t+=a)%=mod;
        n--;
    }
    cout<<sum<<endl;
    return 0;
}
