#line 2 "/Users/kaage/Desktop/ProgrammingWorkspace/library/other/template.hpp"
#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx")
#pragma optimize("O3")
#pragma optimize("unroll-loops")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define all(V) V.begin(),V.end()
typedef long long lint;
typedef unsigned long long ulint;
typedef std::pair<int, int> P;
typedef std::pair<lint, lint> LP;
constexpr int INF = INT_MAX/2;
constexpr lint LINF = LLONG_MAX/2;
constexpr double eps = DBL_EPSILON;
constexpr double PI=3.141592653589793238462643383279;
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
inline lint gcd(lint a, lint b) {
	while (b) {
		lint c = a;
		a = b; b = c % b;
	}
	return a;
}
inline lint lcm(lint a, lint b) {
	return a / gcd(a, b) * b;
}
bool isprime(lint n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
template<typename T>
T mypow(T a, lint b) {
	if (!b)return T(1);
	if (b & 1)return mypow(a, b - 1) * a;
	T memo = mypow(a, b >> 1);
	return memo * memo;
}
lint modpow(lint a, lint b, lint m) {
	if (!b)return 1;
	if (b & 1)return modpow(a, b - 1, m) * a % m;
	lint memo = modpow(a, b >> 1, m);
	return memo * memo % m;
}
template<typename T>
void printArray(std::vector<T>& vec) {
	rep(i, vec.size() - 1)std::cout << vec[i] << " ";
	std::cout << vec.back() << std::endl;
}
template<typename T>
void printArray(T l, T r) {
	T rprev = r;
	rprev--;
	for (T i = l; i != rprev; i++) {
		std::cout << *i << " ";
	}
	std::cout << *rprev << std::endl;
}
#line 2 "main.cpp"
int n,x[200010],y[200010];
char u[200010];
std::vector<std::pair<int,char>> vec[4][400010];
int main(){
	std::cin>>n;
	rep(i,n){
		std::cin>>x[i]>>y[i]>>u[i];
		vec[0][x[i]].emplace_back(y[i],u[i]);
		vec[1][y[i]].emplace_back(x[i],u[i]);
		vec[2][x[i]+y[i]].emplace_back(x[i],u[i]);
		vec[3][x[i]-y[i]+200000].emplace_back(x[i],u[i]);
	}
	rep(i,4){
		rep(j,400001)std::sort(all(vec[i][j]));
	}
	int ans=INF;
	rep(i,400001){
		int now=-1;
		for(const auto& j:vec[0][i]){
			if(j.second=='U')now=j.first;
			if(j.second=='D'&&now!=-1)chmin(ans,(j.first-now)*5);
		}
	}
	rep(i,400001){
		int now=-1;
		for(const auto& j:vec[1][i]){
			if(j.second=='R')now=j.first;
			if(j.second=='L'&&now!=-1)chmin(ans,(j.first-now)*5);
		}
	}
	rep(i,400001){
		int rnow=-1,dnow=-1;
		for(const auto& j:vec[2][i]){
			if(j.second=='R')rnow=j.first;
			if(j.second=='D')dnow=j.first;
			if(j.second=='U'&&rnow!=-1)chmin(ans,(j.first-rnow)*10);
			if(j.second=='L'&&dnow!=-1)chmin(ans,(j.first-dnow)*10);
		}
	}
	rep(i,400001){
		int rnow=-1,unow=-1;
		for(const auto& j:vec[3][i]){
			if(j.second=='R')rnow=j.first;
			if(j.second=='U')unow=j.first;
			if(j.second=='L'&&unow!=-1)chmin(ans,(j.first-unow)*10);
			if(j.second=='D'&&rnow!=-1)chmin(ans,(j.first-rnow)*10);
		}
	}
	if(ans==INF)puts("SAFE");
	else std::cout<<ans<<std::endl;
	return 0;
}