#include <bits/stdc++.h>
#define ll long long
using namespace std;

//GCD,LCM
ll gcd(ll a, ll b){ return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){ return a/gcd(a,b)*b;}

int main()
{
    string S;
    int w;
    cin>>S>>w;

    for(int i=0;i<S.length();i++){
        if(i%w==0){
            cout<<S[i];
        }
    }
    cout<<endl;
    return 0;
}