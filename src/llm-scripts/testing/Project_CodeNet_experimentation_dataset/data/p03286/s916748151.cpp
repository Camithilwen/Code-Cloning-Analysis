#include <bits/stdc++.h>
using namespace std;
long long mypow(long long x, long long y)
{
	long long result = 1;
	while (y != 0) {
		if (y%2 != 0) {
			result *= x;
			y -= 1;
		}	
		x *= x;
		y /= 2;
	}
	return result;
}
int main(void)
{
	long long n;
	cin >> n;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}

	long long base = 0;
	for (int i = 0; i <= 31; i++) {
		if (i % 2 == 1)
			base -= mypow(2, i);
	}
	long long m = n-base;
	string s;
	for (int i = 0; i <= 31; i++) {
		if (m % mypow(2, i+1) != 0) {
			if (i % 2 == 0) {
				s.push_back('1');
			} else {
				s.push_back('0');
			}
			m -= mypow(2, i);
		} else {
			if (i % 2 == 0)
				s.push_back('0');
			else
				s.push_back('1');
		}
	}
	reverse(s.begin(), s.end());
	int i;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			break;
	}
	cout << s.substr(i) << endl;
	return 0;
}