#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int R;
    cin >> R;
    string s;
    if(R < 1200) s = "ABC";
    else if(R < 2800) s = "ARC";
    else s = "AGC";
    cout << s << endl;
}
