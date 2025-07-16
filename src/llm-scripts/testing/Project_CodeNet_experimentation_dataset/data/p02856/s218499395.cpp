#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    int N; cin >> N;
    ll nofd = 0, sum = 0;
    rep(i,N){
        ll d,c; cin >> d >> c;
        nofd += c;
        sum += d*c;
    }
    cout << (nofd - 1) + (sum-1)/9 << endl;
}