#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
int a[4][MAXN];
int b[MAXN];
int c[MAXN], d[MAXN];

void read(){
	scanf("%d", &n);
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}	
}

int solve(){
	for(int i = 1; i <= n; i++){
		int p = a[1][i], q = a[2][i], r = a[3][i];
		if (q % 3 != 2) return 0;
		if (p + r != q * 2) return 0;
		if (abs(p - q) != 1 || abs(r - q) != 1) return 0;
		if (p < r)
			b[i] = r / 3;
		else
			b[i] = -p / 3;
	}	
	for(int i = 1; i <= n; i++){
		if (abs(b[i]) % 2 != i % 2)
			return 0;
	}
	for(int i = 1; i <= n; i++){
		c[abs(b[i])] = i;
	}
	for(int i = 1; i <= n; i++){
		int x = c[i];
		if (x != i){
			d[i] = b[x] * ((x - i) % 4 == 0 ? 1 : -1);
			b[i+1] *= -1;
			b[x] = b[i] * ((x - i) % 4 == 0 ? 1 : -1);
			c[abs(b[x])] = x;
		}
		else
			d[i] = b[i];
	}
	for(int i = 1; i <= n - 2; i++){
		if (d[i] < 0){
			d[i + 2] *= -1;
		}
	}
	return d[n-1] > 0 && d[n] > 0;
	/*
	for(int i = 1; i <= n; i++)
		cout<<b[i]<<' '; cout<<endl;
	int p = 0, q = 0;
	for(int i = 1; i <= n; i++){
		if (i & 1){
			if (abs(abs(b[i]) - i) / 2 % 2 != (b[i] < 0))
				p++;
		}
		else{
			if (abs(abs(b[i]) - i) / 2 % 2 != (b[i] < 0))
				q++;
		}
	}
	cout<<p<<' '<<q<<endl;
	return p % 2 == q % 2;*/
}

void printans(int flag){
	puts(flag ? "Yes" : "No");
}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		;
		printans(solve());
	}
	return 0;
} 
