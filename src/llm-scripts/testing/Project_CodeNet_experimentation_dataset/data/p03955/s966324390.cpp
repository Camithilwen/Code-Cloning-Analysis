//2017-11-7
//miaomiao
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define LL long long
#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)
 
#define N (100000+5)
 
bool Check(int a, int b, int c){
	if(a > c) swap(a, c);
	if(b != a+1 || c != a+2) return false;
	if(a % 3 != 1) return false;
	return true;
}
 
int a[N][5], num[N];
bool op[N], rev[2], swp[2];
 
int main(){
	int n;
 
	scanf("%d", &n);
	For(j, 1, 3) For(i, 1, n) scanf("%d", &a[i][j]);
	
	For(i, 1, n) if(!Check(a[i][1], a[i][2], a[i][3])){
		puts("No"); return 0;
	}
 
	For(i, 1, n){
		num[i] = max(a[i][1], a[i][3]) / 3;
		op[i] = a[i][1] > a[i][3];
		if((num[i]&1) ^ (i&1)){
			puts("No"); return 0;
		}
	}
 
//	For(i, 1, n) printf("%d%c ", num[i], op[i]? '-': '+');
//	puts("");
 
	For(i, 1, n) rev[i&1] ^= op[i];

	int t;
	For(i, 1, n)
		while(i != num[i]){
			t = num[i];
			swap(num[i], num[t]);
			swp[i&1] ^= 1;
		}
 
	if((swp[0] ^ rev[1]) || (swp[1] ^ rev[0])) puts("No");
	else puts("Yes");
 
	return 0;
}
