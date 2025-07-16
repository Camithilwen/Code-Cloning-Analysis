#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll ans = 1;
    while(pow(ans, 2) <= n){
        ans++;
    }
    cout << (ll)pow(ans-1, 2) << endl;
}