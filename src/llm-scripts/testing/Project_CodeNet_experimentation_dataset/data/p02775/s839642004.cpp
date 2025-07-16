#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    S = "00" + S;
    int N = S.length();
    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] > '9') {
            S[i - 1]++;
            S[i] -= 10;
        }
        if(S[i] <= '4' || (S[i] == '5' && S[i - 1] < '5')) {
            ans += S[i] - '0';
        } else {
            ans += 10 - (S[i] - '0');
            S[i - 1]++;
        }
    }
    cout << ans << endl;

    return 0;
}
