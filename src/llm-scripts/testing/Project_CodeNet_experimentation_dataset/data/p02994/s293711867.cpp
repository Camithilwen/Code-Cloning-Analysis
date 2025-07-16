#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,l;
    cin >> n >> l;
    vector<int> taste(n);
    rep(i,n){
        taste[i] = l + i;
    }
    int total = 0;
    rep(i,n) total += taste[i];
    if(l >= 0) total -= taste[0];
    else if(n+l <= 0) total -= taste[n-1];
    cout << total << endl;
    return 0;
}