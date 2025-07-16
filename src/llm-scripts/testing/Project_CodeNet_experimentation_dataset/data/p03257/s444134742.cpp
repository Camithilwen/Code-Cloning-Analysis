#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 507;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
LL tab[N][N];
vector <int> primes;

LL nwd(LL a, LL b){
	if(b == 0)
		return a;
	return nwd(b, a%b);
}

LL get(LL a, LL b, LL c, LL d){
	LL ret = a / nwd(a, b) * b;
	ret = ret / nwd(ret, c) * c;
	ret = ret / nwd(ret, d) * d;
	return ret;
}

bool ok(int a){
	for(int i = 2; i * i <= a; ++i)
		if(a%i == 0)
			return false;
	return true;
}

int main(){
	scanf("%d", &n);
	if(n == 2){
		puts("2 3\n5 4");
		return 0;
	}

	for(int i = 2; primes.size() < n + n; ++i)
		if(ok(i))
			primes.push_back(i);
	
	for(int i = 0; i <= n + 1; ++i)
		for(int j = 0; j <= n + 1; ++j)
			tab[i][j] = 1;
	
	int sx = n - 1 + (n & 1), sy = 1;
	for(int i = 1; i <= n - 1 + (n & 1); ++i){
		int cx = sx, cy = sy;
		while(cx <= n && cy <= n){
			tab[cx][cy] *= primes.back();
			++cx, ++cy;
		}
		
		if(sx > 2)
			sx -= 2;
		else{
			if(sy == 1 && sx == 2)
				sx = 1, sy++;
			else
				sy += 2;
		}
		
		primes.pop_back();
	}
	
	sx = 1, sy = 1;
	for(int i = 1; i <= n; ++i){
		int cx = sx, cy = sy;
		while(cx <= n && cy >= 1){
			tab[cx][cy] *= primes.back();
			++cx, --cy;
		}
		
		if(sy + 1 < n)
			sy += 2;
		else{
			if(sx == 1 && sy + 1 == n)
				sy = n, ++sx;
			else
				sx += 2;
		}
		
		primes.pop_back();
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if((i + j) & 1)
				tab[i][j] = get(tab[i - 1][j], tab[i][j - 1], tab[i + 1][j], tab[i][j + 1]) + 1;
			printf("%lld ", tab[i][j]);
		}

		puts("");
	}
	
	return 0;
}