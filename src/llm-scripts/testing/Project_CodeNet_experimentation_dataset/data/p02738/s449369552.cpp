#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL; using namespace std;

int N, M;
const int OFFSET = 2000;

LL dp[6001][8001];

LL memo(int total, int dif) {
	if (dif < 0)
		return 0LL;
	if (!total)
		return dif >= OFFSET;
		
	LL &ret = dp[total][dif];
	if (ret != -1)
		return ret;
	
	ret = 0LL;
	
	if (total >= 3)
		ret += (total - 1LL) * (total - 2LL) * memo(total - 3, dif);
	if (total >= 2)
		ret += (total - 1LL) * memo(total - 2, dif - 1);
	ret += memo(total - 1, dif + 1);
	
	ret %= M;
	return ret;
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	
	cin >> N >> M;
	
	SET(dp, 255);
	
	cout << memo(3 * N, OFFSET) << endl;
	
	return 0;
}