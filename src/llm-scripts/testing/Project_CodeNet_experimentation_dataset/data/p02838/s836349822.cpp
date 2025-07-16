#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
 
long long dataset[300005]={0};
 
int main()
{
    int number;
    cin>>number;
 
    for(int i=0;i<number;i++)
        cin>>dataset[i];
 
    ll result=0;
    for(ll i=0;i<62;i++)
    {
        long long zeros=0,ones=0;
 
        for(ll j=0;j<number;j++)
        {
            if(dataset[j]%2ll==1)
                ones++;
            else
                zeros++;
            dataset[j]/=2ll;
        }
        result+=((ones*zeros)%MOD*((1ll<<i)%MOD))%MOD;
      result%=MOD;
 
    }
    cout<<result<<endl;
}
