#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int N;
    cin >> N;

    set<ll> numbers; 
    map<ll, ll> map_numbers;
    REP(i, N) {
        ll tmp;
        cin >> tmp;
        numbers.insert(tmp);
        map_numbers[tmp]++;
    }

    ll ans = 0;
    FORR(t, 37, 1) {
        ll x = pow(2, t-1);
        ll y = pow(2, t);

        if(numbers.size() == 0) break;
        ll max = *numbers.rbegin();
        if(max < x) continue;
        
        set<ll> to_remove;
        for(auto a = numbers.rbegin(); a != numbers.rend(); ++a) {
            if(map_numbers[*a]==0) continue;
            if(*a < x) break;
            if(map_numbers[y - *a]>0 && *a != y - *a) {
                ll num_pair = min(map_numbers[*a], map_numbers[y-*a]);
                ans+=num_pair;
                map_numbers[y-*a]-=num_pair;
                map_numbers[*a]-=num_pair;
                if(map_numbers[*a] == 0) 
                    to_remove.insert(*a);
                if(map_numbers[y-*a] == 0)
                    to_remove.insert(y-*a);
            } else if(map_numbers[y - *a]>=2 && *a == y - *a) {
                ll num_pair = map_numbers[*a] / 2;
                ans+=num_pair;
                map_numbers[*a]-=num_pair;
                if(map_numbers[*a] == 0) 
                    to_remove.insert(*a);
            } else {
                map_numbers[*a] = 0;
                to_remove.insert(*a);
            }
        }

        for(ll r: to_remove) {
            numbers.erase(numbers.find(r));
        }
    }

    cout << ans << endl;

    return 0;
}
