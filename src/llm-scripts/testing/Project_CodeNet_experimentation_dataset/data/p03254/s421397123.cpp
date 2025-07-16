#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
bool prime(int n) {
	if (n == 1)return false;
	if (n == 2)return true;
	if (n == 3)return true;
	if (n == 4)return false;
	for (int i = 2; i < ceil(sqrt(n)); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int lst[110];
int main() {
	int n,x,rec;
	cin >> n>>x;
	long long sum=0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	sort(lst, lst + n);
	for (int i = 0; i < n; i++) {
		sum += lst[i];
		if (sum <= x)ans++;
		else break;
	}
	if (sum < x) {
		cout << ans - 1 << endl;
	}
	else cout << ans << endl;
	return 0;
}