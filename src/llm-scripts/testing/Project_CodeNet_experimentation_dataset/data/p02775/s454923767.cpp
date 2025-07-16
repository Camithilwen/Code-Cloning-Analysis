#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    string n;
    cin >> n;
    int len = n.size();
    vector<ll> tmp(2);
    vector<vector<ll>> bill(len, tmp);
    bill[0][0] = n[len-1] - '0';
    bill[0][1] = 10 - (n[len-1] - '0');
    rep2(i, 1, len){
      int x = n[len - 1 - i] - '0';
      bill[i][0] = min(bill[i - 1][0] + x, bill[i-1][1] + x + 1);
      bill[i][1] = min(bill[i-1][0] + 10 - x, bill[i-1][1] + 9 - x);
    }
    cout << min(bill[len-1][0], bill[len-1][1]+1) << endl;
    return 0;
}