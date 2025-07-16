#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr int NMAX = 302;

ll bilang[NMAX][NMAX][NMAX]; // (# of chars left in target, opcount, # of ones I ate)
char simula[NMAX];
int lenToZero[NMAX];

ll bilangin(int i, int j, int k) {
	if (i < 0 || j < 0 || k < 0 ||
		i >= NMAX || j >= NMAX || k >= NMAX) return 0;
	else return bilang[i][j][k];
}

int main() {
	scanf("%s", simula);
	int k; scanf("%d", &k);
	int n = strlen(simula);
	for (int i = 0; i < n; ++i) {
		if (simula[i] == '0') lenToZero[i] = 0;
		else lenToZero[i] = (i == 0 ? 1000000 : 1 + lenToZero[i-1]);
	}
	bilang[0][0][0] = 1;
	for (int targetLen = 1; targetLen <= n; ++targetLen) {
		for (int opcount = 0; opcount <= n; ++opcount) {
			for (int kinain = 0; kinain <= targetLen; ++kinain) {
				int sourceLen = targetLen - kinain;
				if (sourceLen == 0) {
					bilang[targetLen][opcount][kinain] = opcount == 0 ? 1 : 0;
					continue;
				}
				if (simula[sourceLen - 1] == '0') {
					bilang[targetLen][opcount][kinain] = (bilangin(targetLen - 1, opcount, kinain)
							+ bilangin(targetLen - 1, opcount, kinain - 1)) % MOD;
				} else {
					bilang[targetLen][opcount][kinain] = 
						(bilangin(targetLen - 1, opcount - lenToZero[sourceLen - 1], kinain + lenToZero[sourceLen - 1])
							+ bilangin(targetLen - 1, opcount, kinain)) % MOD;
				}
//				printf("t = %d s = %d o = %d k = %d is %lld\n", targetLen, sourceLen, opcount, kinain,
//						bilangin(targetLen, opcount, kinain));
			}
		}
	}
	ll ans = 0;
	for (int finalOps = 0; finalOps <= min(k, n); ++finalOps) ans = (ans + bilangin(n, finalOps, 0)) % MOD;
	printf("%lld\n", ans);
	return 0;
}
