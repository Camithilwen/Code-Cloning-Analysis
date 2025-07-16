#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const int MAX = 18;

int main() {
	int n;
	cin >> n;
	ll ans = 0;

	vector<vector<ll>> c(MAX + 1, vector<ll>(MAX + 1));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;


		ll a = 0;

		bool isD = false;
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (isD) {
				cnt++;
			}
			if (s[i] == '.') {
				isD = true;
				continue;
			}

			
			a = a * 10 + s[i] - '0';
		}

		while (cnt < 9) {
			a *= 10;
			cnt++;
		}

		
		//cout << a << endl;
		int cnt2 = 0;
		int cnt5 = 0;
		while (a % 2 == 0) {
			cnt2++;
			a /= 2;
		}

		cnt2 = min(cnt2, MAX);

		while (a % 5 == 0) {
			cnt5++;
			a /= 5;
		}


		cnt5 = min(cnt5, MAX);




		for (int i = 0; i <= MAX; i++) {
			if (i + cnt2 < MAX) {
				continue;
			}
			for (int j = 0; j <= MAX; j++) {
				if (j + cnt5 < MAX) {
					continue;
				}
				ans += c[i][j];
			}
		}
		




		
		c[cnt2][cnt5]++;

	}
	cout << ans << endl;
	
	/*
	cout.fill(' ');
	cout << "   ";
	for (int i = 0; i <= MAX; i++) {
		cout << setw(2) << i << " ";
	}
	cout << endl;
	for (int i = 0; i <= MAX; i++) {
		cout << setw(2) << i << " ";
		for (int j = 0; j <= MAX; j++) {
			cout << setw(2) << c[i][j] << " ";
		}
		cout << setw(2) << endl;
	}
	*/

}