#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

vector<string> a;

bool cmp(string s, string t) {
    if (s.length() != t.length()) return s.length() < t.length();
    return s < t;
}

void sol(string s) {
    a.push_back(s);
    if (s.length() == 10) return;
    if (s.back() != '0') {
        s += (s.back() - 1);
        sol(s);
        s.pop_back();
    }
    s += (s.back());
    sol(s);
    s.pop_back();
    if (s.back() != '9') {
        s += (s.back() + 1);
        sol(s);
        s.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    cout << c << ' ' << a << ' ' << b;
}
