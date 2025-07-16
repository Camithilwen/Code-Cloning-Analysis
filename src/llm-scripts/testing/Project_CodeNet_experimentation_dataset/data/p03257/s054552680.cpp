#include <iostream>
#define ll long long
using namespace std;
bool mx[1003][1003], flag[10004];
ll a[1003], b[1003], ans[1003][1003];
ll prime[10004];
ll gcd(ll x, ll y){
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
ll lcm(ll x, ll y){
	if (x == 0 || y == 0)
		return x + y;
	return x / gcd(x, y) * y;
}
int main(){
	int prime_cnt = 0;
	for (int i = 2; i <= 10000; ++ i){
		if (! flag[i])
			prime[++ prime_cnt] = i;
		for (int j = 2; i * j <= 10000; ++ j){
			flag[i * j] = true;
			if (i % j == 0)
				break;
		}
	}
	int n;
	cin >> n;
	if (n == 2){
		cout << "4 7" << endl << "23 10" << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (i % 2 == j % 2)
				mx[i][j] = true;
	int cnt = 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (! mx[i][j]){
				//if (! a[i + j])
					//a[i + j] = prime[++ cnt];
				//if (! b[i - j + n])
					//b[i - j + n] = prime[++ cnt];
				//ans[i][j] = a[i + j] * b[i - j + n];
				ans[i][j] = prime[(i + j) / 2] * prime[(i + n + 1 - j) / 2 + n];
			}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (mx[i][j])
				ans[i][j] = lcm(lcm(ans[i - 1][j], ans[i + 1][j]), lcm(ans[i][j - 1], ans[i][j + 1])) + 1;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}
