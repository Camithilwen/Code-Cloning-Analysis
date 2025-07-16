#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include<stack>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;


template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
map<T, T> getPrimeFactor(T n) {
	map<T, T> res;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i] ++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

template<typename T>
bool IsPrimeNumber(T num)
{
	if (num <= 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)


int main() {
	ll N;
	std::cin >> N;

	vector<map<ll, ll>> dic(N+1);
	rep(i, 1, N) {
		ll a, b, c;
		std::cin >> a >> b >> c;
		dic[a][b] = c;
		dic[b][a] = c;
	}

	ll Q, K;
	std::cin >> Q >> K;

	vll cost(N+1, 999999999999999);
	cost[K] = 0;
	vector<bool> isVisited(N + 1, false);
	priority_queue<pair<ll, ll>> pq;
	pq.push({ 0,K });
	while (!pq.empty()) {
		if (!isVisited[pq.top().second]) {
			isVisited[pq.top().second] = true;
			ll c = pq.top().first;
			ll pos = pq.top().second;
			pq.pop();

			for (auto itr = dic[pos].begin(); itr != dic[pos].end(); itr++) {
				if (c + itr->second < cost[itr->first]) {
					cost[itr->first] = c + itr->second;
					pq.push({ cost[itr->first],itr->first });
				}
			}
		}
	}

	rep(i, 0, Q) {
		ll x, y;
		std::cin >> x >> y;
		std::cout << cost[x] + cost[y] << endl;
	}


	return 0;
}
