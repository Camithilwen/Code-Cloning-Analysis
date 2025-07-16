#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)
#define REP(i, n) FOR((i), 0, (n))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T>
void print_container(T &container, string delim=" ") {
    bool first = true;
    for(auto &t: container){
        if(!first){
            cout << delim;
        }
        first = false;
        cout << t;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n)
        cin >> a[i];

    vector<ll> dp(n+1);
    dp[0] = 0;
    dp[1] = 0;

    ll accum = a[0];
    IFOR(i, 2, n){
        if(i % 2 == 0){
            dp[i] = max(dp[i-2] + a[i-1], accum);
        }
        else{
            accum += a[i-1];
            dp[i] = max(dp[i-2] + a[i-1], dp[i-1]);
        }
    }

    cout << dp[n] << endl;

    
    return 0;
}