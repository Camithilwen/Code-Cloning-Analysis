#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


void solve()
{
    string s;cin>>s;
    if(s=="MON")
    cout<<6<<endl;
    else if(s=="TUE")
    cout<<5<<endl;
    else if(s=="WED")
    cout<<4<<endl;
    else if(s=="THU")
    cout<<3<<endl;
    else if(s=="FRI")
    cout<<2<<endl;
    else if(s=="SAT")
    cout<<1<<endl;
    else
    cout<<7<<endl;
    
}
int32_t main()
{
    rapido;
    int t;
    //cin>>t;
      t=1;
    while(t--)
    solve();
}