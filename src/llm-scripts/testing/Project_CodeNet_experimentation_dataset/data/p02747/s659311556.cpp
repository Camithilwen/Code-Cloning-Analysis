#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#include<functional>
//#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll yo[12345678], ta[12345678];
signed main() {
    ll n = 0, m;
    string s; cin >> s;
    if (s.size() % 2 == 1) { cout << "No" << endl; return 0; }
    for (int h = 0; h < s.size(); h++) {
        if (h % 2 == 0) {
            if (s[h] != 'h') { n++; }
        }
        else {
            if (s[h] != 'i') { n++; }
        }
    }
    if (n == 0) { cout << "Yes" << endl; }
    else { cout << "No" << endl; }
    return 0;
}