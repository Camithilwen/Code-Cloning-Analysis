#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

#define int long long

const int N = 3e5 + 5 , mod = 1e9 + 7;

//void add(int &x , int y){
//	x += y;
//	if(x >= mod)
//		x -= mod;
//}

char s[N];

long long n , ans;

long long f[N][3][3];

void add(long long &a, long long b) {
	a += b, ((a > mod) ? (a -= mod) : 0);
}

main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	f[0][0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				if(s[i + 1] != '0') {
					if(k)
						add(f[i + 1][j][k - 1], f[i][j][k]);
					else add(f[i + 1][min(j + 1, (long long)2)][k], f[i][j][k]);
				}
				if(s[i + 1] != '1') {
					if(k == 2)
						add(f[i + 1][j][1], f[i][j][k]);
					else add(f[i + 1][j][k + 1], f[i][j][k]);
				}
			}
		}
	}
	for(int i = 0; i < 3; i++)
		for(int j = 0; j <= i; j++)
			add(ans, f[n][i][j]);
	cout << ans;
	return 0;
}