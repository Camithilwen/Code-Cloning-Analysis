//Radhe Radhe
#include<bits/stdc++.h>//157B
#define ll long long
#define fixed cout.setf(ios::fixed);
#define rep1    for( i=0; i<n; i++)
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll i,j,n;
    cin>>n;
   // ll a[n];
    ll x,cnt=0,sum=0,mini=INT_MAX;
    for(i=0; i<n; i++){
        cin>>x;
        if(x<0) cnt++;
        mini=min(mini,abs(x));
        sum+=abs(x);
    }
    if(cnt%2)
    sum-=(2*mini);
    cout<<sum<<endl;
    return 0;
}



