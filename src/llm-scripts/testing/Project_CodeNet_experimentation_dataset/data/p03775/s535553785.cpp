#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long
#define lli long long int

using namespace std;
using P = pair<int,int>;

int dignum(ll n) {
  int res = 0;
  while(n > 0) {
    res++;
    n /= 10;
  }
  return res;
}

int main(){

  ll N;
  cin >> N;

  int ans = dignum(N); // 最大の桁数を求めて億

  for (ll A = 1; A*A <= N; A++) { // Aを1からNまで、A*Aつまり√Aで求める。Nが100ならAは1〜10になる
    if(N%A != 0) continue; // NがAで割り切れない場合は飛ばす
    ll B = N/A;

    int cur = max(dignum(A), dignum(B)); // 関数F（AとBの大きい桁数を保存する)

    ans = min(ans, cur); // 最小の値を求める
  }

  cout << ans << endl;

  return 0;
}