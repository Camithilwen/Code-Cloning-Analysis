#include <bits/stdc++.h>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define N 200005
using namespace __gnu_pbds;
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
LL z = 1;
int read(){
	int x, f = 1;
	char ch;
	while(ch = getchar(), ch < '0' || ch > '9') if(ch == '-') f = -1;
	x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - 48;
	return x * f;
}
int ksm(int a, int b, int p){
	int s = 1;
	while(b){
		if(b & 1) s = z * s * a % p;
		a = z * a * a % p;
		b >>= 1;
	}
	return s;
}
LL s[N];
int main(){
	int i, j, n, m, x, y;
	LL s1, s2, s3, s4, ans = 1e18, a, b;
	n = read();
	for(i = 1; i <= n; i++) s[i] = s[i - 1] + read();
	x = 1, y = 3;
	for(i = 2; i <= n - 2; i++){
		while(x + 1 < i && abs(s[i] - s[x] - s[x]) > abs(s[i] - s[x + 1] - s[x + 1])) x++;
		while(y + 1 < n && abs(s[n] - s[y] - (s[y] - s[i])) > abs(s[n] - s[y + 1] - (s[y + 1] - s[i]))) y++;
		s1 = s[x], s2 = s[i] - s[x];
		s3 = s[y] - s[i], s4 = s[n] - s[y];
		a = max(s1, s2); a = max(a, max(s3, s4));
		b = min(s1, s2); b = min(b, min(s3, s4));
		ans = min(ans, a - b);
	}
	printf("%lld", ans);
	return 0;
}
