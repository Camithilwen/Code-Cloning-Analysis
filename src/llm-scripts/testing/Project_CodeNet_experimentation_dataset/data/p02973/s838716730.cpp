#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    reverse(A.begin(), A.end());
    vector<ll> dp(N,INF);
    for(int i = 0; i < N; i++){
        auto iter = upper_bound(dp.begin(), dp.end(), A[i]);
        ll idx = iter - dp.begin();
        dp[idx] = A[i];
    }
    cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin() << endl;
}