#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define fore(i, a) for (auto &i:a)
#define ll long long
#define pll vector<pair<ll, ll>>
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define popcount(x) __builtin_popcountll(x)

using namespace std;

const long double PI = acos(-1);

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}

bool isInteger(double x){return floor(x) == x;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a,b,c,d;cin >> a >> b >> c >> d;

	cout << min(a,b)+min(c,d) << endl;
}