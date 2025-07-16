#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <numeric>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cmath>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)
#define rrep(i, n) for (int i=(int)(n)-1;i>=0;--i)
#define rrep1(i, n) for (int i=(int)(n);i>=1;--i)
#define range(i, l, r) for (int i=l;i<(int)(r);++i)
#define rrange(i, l, r) for (int i=(int)(r)-1;i>=l;--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;
using vpii=vector<pii>;
using ll=long long;

constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}
template<typename T>bool chmin(T&a,T b){return a>b?(a=b,1):0;}
template<typename T>bool chmax(int&a,int b){return a<b?(a=b,1):0;}
int read(){int a;scanf("%lld",&a);return a;}

const double pi = acos(-1);
constexpr int inf = 3*TEN(18) + 10;

signed main()
{
	int N,A,B; cin >> N >> A >> B;
	vi X(N);
	rep(i, N) cin >> X[i];

	int ans = 0, cur = X[0];
	rep(i, N - 1) {
		ans += min((X[i + 1] - cur) * A, B);
		cur = X[i + 1];
	}

	cout << ans << endl;
}


