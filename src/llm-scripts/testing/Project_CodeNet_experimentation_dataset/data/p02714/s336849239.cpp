#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n;
    string s;
    cin >> n >> s;
    ll r=0,g=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R') r++;
        else if(s[i]=='G') g++;
        else b++;
    }
    ll sum=r*g*b;
    for(int i=0;i<n-2;i++){
        for(int j=i+2;j<n;j++){
            if((i+j)%2!=0) continue;
            if(s[i]!=s[(i+j)/2] && s[i]!=s[j] && s[j]!=s[(i+j)/2]) sum--;
        }
    }
    cout << sum << endl;
}