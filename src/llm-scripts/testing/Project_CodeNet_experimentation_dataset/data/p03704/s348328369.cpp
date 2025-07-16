#include<cstdio>
#include<algorithm>
using namespace std;
long long K;
long long po[20], C[20], res;
void Do(int b, int e, long long S, long long c) {
	if (!c)return;
	if (b >= e) {
		if (S == K) {
			if (b == e)res += 10*c;
			else res+=c;
		}
		return;
	}
	if (abs(S - K) > po[e + 1])return;
	int i;
	for (i = -9; i <= 9; i++) {
		int t = 10 - abs(i);
		if (i >= 0 && b==0)t--;
		Do(b+1, e-1, S+i*C[b], t*c);
	}
}
void Calc(int L) {
	int i;
	for (i = 0; i < L; i++) {
		C[i] = po[L - i - 1] - po[i];
	}
	Do(0, L - 1, 0, 1);
}
int main() {
	int i;
	po[0] = 1;
	for (i = 1; i <= 18; i++)po[i] = po[i - 1] * 10;
	scanf("%lld", &K);
	for (i = 2; i <= 18; i++) {
		Calc(i);
	}
	printf("%lld\n", res);
}