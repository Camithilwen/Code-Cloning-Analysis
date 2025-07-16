#include <bits/stdc++.h>
#define ll long long
using namespace std;

// GCD, LCM
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
 
int main()
{
    int A,B,K;

    cin>>A>>B>>K;

    for(int i=1;i<=K;i++){
        if(i%2==1){
            A/=2;
            B+=A;
        }else{
            B/=2;
            A+=B;
        }
    }

    cout<< A << " "<<B<<endl;
 
    return 0;
}