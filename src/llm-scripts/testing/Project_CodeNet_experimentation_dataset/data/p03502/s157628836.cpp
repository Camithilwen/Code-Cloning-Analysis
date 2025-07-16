#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
const int MOD = 1000000009;
const double pi = acos(-1);

int dist_sum(int N) {
    int ans = 0;
    while(N > 0) {
        ans += N%10;
        N /= 10;
    }
    return ans;
}

int main() {
    int N; cin >> N;
    cout << (N%dist_sum(N) == 0 ? "Yes" : "No") << endl;
}