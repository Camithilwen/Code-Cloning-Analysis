#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <functional>
#include <bitset>
#include <limits>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <random>

#ifdef DEBUG
#include "library/Utility/debug.cpp"
#else
#define debug(...)
#endif

#define rep(i,n) for(int i=0;i<(n);++i)
#define EL '\n'
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
using lnt = long long;
struct FIO{FIO(){std::cin.tie(0);std::cout.tie(0);std::ios_base::sync_with_stdio(0);std::cout<<std::setprecision(15);}}fIO;
template<typename T> using V = std::vector<T>;
template<typename T> void fill(V<T>&v) { for(T&e:v) std::cin >> e; }
/*-*/

int main() {
	std::string s;
	std::cin >> s;
	std::map<char, lnt> map;
	lnt n=s.size();
	lnt ans=n*n;
	for(auto c:s) map[c]++;
	for(auto e:map) {
		ans-=e.second*e.second;
	}
	print(ans/2+1);
}
