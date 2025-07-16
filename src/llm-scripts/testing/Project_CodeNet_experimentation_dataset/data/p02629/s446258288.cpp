#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
ll Max = 10 + 1e12;
int N = 5 + 1e5;

int main()
{
	ll n;
	string rr = "";
	cin >> n;
	while (n>0) {
		int xx = n % 26;
		n /= 26;
		if (xx == 0) {
			rr += "z";
			n--;
		}
		else {
			rr += (char)('a' + (xx - 1));
		}
	}
	reverse(rr.begin(), rr.end());
	cout << rr;
}