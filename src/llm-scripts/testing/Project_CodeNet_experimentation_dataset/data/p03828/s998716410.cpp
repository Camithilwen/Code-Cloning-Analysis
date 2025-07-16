#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int div(int x) {
	int cnt = 0;
	for (int i = 1; i <= x;i++) {
		if (x % i == 0)cnt++;
	}
	return cnt;
}
bool prime(long long int x) {
	for (int i = 2; i <= sqrt(x) ;  i++) {
		if (x % i == 0)return 0;
	}
	return 1;

}

long long int divi(long long int n,long long int p) {
	int cn = 0;
	int q = p;
	while (n / q != 0) {
		cn += n / q;
		q = q * p;
	}
	return cn;
}

int main() {
	long long int n;
	int cnt = 0;
	long long int ans = 1;
	cin >> n;
	vector<int> p(n);
	vector<int> a(n);

	for (int i = 2; i <= n; i++) {
		if (prime(i) == 1) {
			p.at(cnt) = i;
			cnt++;
		}
	}
	//for (int i = 0; i < cnt; i++)cout << p.at(i) << endl;

	for (int i = 0; i < cnt; i++) {
		a.at(i) = divi(n, p.at(i));
	}


	for (int i = 0; i < cnt; i++) {
		ans =(ans%MOD) * (a.at(i)+1)%MOD;
	}
	
	cout << ans%MOD << endl;


	return 0;
}