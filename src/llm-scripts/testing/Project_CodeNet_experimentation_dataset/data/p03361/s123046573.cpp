#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<iomanip>
#include<numeric>
#include<queue>
#include<deque>
#include<cfloat>
#include<functional>
#include<tuple>
#include<math.h>
#include<bitset>
#include<stack>
#include<set>
#include<random>
#include<stdlib.h>
#define rip(i,n) for(int i=0;i<n;i++)
#define Rip(i,n) for(int i=1;i<=n;i++)
#define RIP(i,a,b) for(int i=a;i<b;i++)
#define all(V) V.begin(),V.end()
#define sec  setprecision;
#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx")
#pragma optimize("O3")
#pragma optimize("unroll-loops");
constexpr double eps = 1e-9;
constexpr double pi = 3.141592653589793238462643383279;
using namespace std;
using ll = long long;
using ld = long double;
using Pa = pair<int, int>;
ll mod = 1000000007;
ll MOD = 998244353;
ll gcd(ll a, ll b)
{
	if (a % b == 0)	return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
ll pow(ll x, ll n) {
	x %= mod;
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return (pow((x * x) % mod, n / 2) % mod);
	else
		return (x * pow(x, n - 1)) % mod;
}
bool prime(int n) {
	int i = 2;
	if (n == 2)return true;
	else if(n <= 1)return false;
	if (n % i == 0)return false;
	i = 3;
	while (i <= sqrt(n)) {
		if (n % i == 0)return false;
		i += 2;
	}
	return true;
}
signed main() {
	int h, w; cin >> h >> w;
	vector<vector<bool>>s(h+2,vector<bool>(w+2,false));
	rip(i, h){
      rip(j, w) {
		char a; cin >> a;
		if (a == '#')s[i+1][j+1] = true;
		}
    }
	rip(i, h) {
		rip(j, w) {
			bool p = true;
          int k=i+1;int l=j+1;
			p = s[k-1][l]||s[k][l-1]||s[k+1][l]||s[k][l+1];
			if(p == false&&s[k][l]==true) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}