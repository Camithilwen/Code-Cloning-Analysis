#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll N;
    cin >> N;

    multiset<string> mp;
    string s;
    string S[N];
    rep(i, N){
        cin >> s;
        S[i] = s;
        mp.insert(s);
    }

    ll M;
    cin >> M;
    multiset<string> mn;
    rep(i, M){
        cin >> s;
        mn.insert(s);
    }

    ll ans = 0;
    ll count;
    rep(i, N){
        count = mp.count(S[i]) - mn.count(S[i]);
        ans = max(ans, count);
    }

    cout << ans << endl;

    return 0;
}