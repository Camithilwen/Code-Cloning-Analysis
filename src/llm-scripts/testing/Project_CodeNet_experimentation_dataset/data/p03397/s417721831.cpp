/*
* @Author: wxyww
* @Date: 2020-03-31 09:07:10
* @Last Modified time: 2020-03-31 09:20:33
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 300010,mod = 1e9 + 7;
ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
char s[N];
int e[9][2],f[10][N];
void add(int &x,int y) {
	(x = x + y) >= mod ? x -= mod : 0;
}
int main() {
	e[1][0] = 2;e[1][1] = 5;
	e[2][0] = 3;e[2][1] = 4;
	e[3][0] = 2;e[3][1] = 2;
	e[4][0] = 2;e[4][1] = 5;
	e[5][0] = 7;e[5][1] = 6;
	e[6][0] = 6;e[6][1] = 6;
	e[7][0] = 8;e[7][1] = 5;
	e[8][0] = 7;e[8][1] = 7;
	scanf("%s",s + 1);
	int n = strlen(s + 1);

	f[1][0] = 1;

	for(int i = 0;i < n;++i) {
		for(int j = 1;j <= 8;++j) {
			if(s[i + 1] == '1' || s[i + 1] == '?') 
				add(f[e[j][1]][i + 1],f[j][i]);
			if(s[i + 1] == '0' || s[i + 1] == '?')
				add(f[e[j][0]][i + 1],f[j][i]);
		}
	}

	cout<<(f[6][n] + f[5][n]) % mod;



	return 0;
}