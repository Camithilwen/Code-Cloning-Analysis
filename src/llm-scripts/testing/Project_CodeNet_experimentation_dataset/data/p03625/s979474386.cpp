#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    sort(A.begin(),A.end());
    ll h=0,v=0;
    for(int i=n-1;i>0;i--){
        if(h==0){
            if(A[i]==A[i-1]){
                h=A[i];
                i--;
            }
        }else{
            if(A[i]==A[i-1]){
                v=A[i];
                break;
            }
        }
    }
    ll ans=h*v;
    cout << ans << endl;
}