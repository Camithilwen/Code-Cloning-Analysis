#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<int(n); i++)
using namespace std;

const int MAX = 7000;

// fac[]・・・a! finv[]・・・(a!)^(-1) inv[]・・・a^(-1)

long long N, M, ans, fac[MAX], finv[MAX], inv[MAX], two[MAX], six[MAX];

void pre_comb(void){
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	two[0] = 1; two[1] = 2;
	six[0] = 1; six[1] = 6;
	for(int i=2; i<MAX; i++){
		fac[i] = fac[i-1] * i % M;
		inv[i] = M - inv[M % i] * (M/i) % M;
		finv[i] = finv[i-1] * inv[i] % M;
		two[i] = two[i-1] * 2 % M;
		six[i] = six[i-1] * 6 % M;
	}
}

long long comb(int n, int k){
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n-k] % M) % M;
}

long long mpow(long long n, long long r){
	if(r == 1) return n;
	if(r % 2 == 1) return n * mpow(n, r-1) % M;
	else{
		long long a = mpow(n, r/2);
		return a * a % M;
	}
}

long long inve(long long n){
	return mpow(n, M-2);
}

int main(){
	cin >> N >> M;
	pre_comb();
	rep(i, N+1){
		rep(j, (3*N/2)+1){
			if(3*N - 2*j - 3*i >= j){
				long long t1 = (fac[3*N] * finv[3*N-3*i-2*j] % M) * two[i] % M;
				long long t2 = t1 * inve(six[i] * two[j] % M) % M;
				ans = (ans + (t2 * finv[i] % M) * finv[j] % M) % M;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
