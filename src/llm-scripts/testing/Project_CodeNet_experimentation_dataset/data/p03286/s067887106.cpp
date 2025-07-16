#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a=-2,b;
    cin>>n;b=n;
    string s;
    while(n!=0){
        if((n%a)<0){s+=(2+(n%a))+'0';n/=a;n+=1;}
        else {s+=(n%a)+'0';n/=a;}
    }
    reverse(s.begin(),s.end());
    if(b!=0)cout<<s<<endl;
    else cout<<0<<endl;
}
