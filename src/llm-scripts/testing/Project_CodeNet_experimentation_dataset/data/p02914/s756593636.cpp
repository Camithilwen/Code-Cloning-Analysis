#include <cstdio>
#include <vector>
using namespace std;

typedef long long i64;

int main()
{
	int n;
	vector<i64> as;

	scanf("%d", &n);
	as.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &as[i]);
	}

	i64 sum = 0;
	for(auto& a : as) {
		sum = sum ^ a;
	}

	for(auto& a : as) {
		a = a & (~sum);
	}

	i64 maxi = 0;

	for(int b = 62; b >= 0; b--) {

		i64 v = -1;

		for(int i = 0; i < n; i++) {
			if((as[i] & (1LL << b)) != 0) {
				v = as[i];
				break;
			}
		}

		if(v == -1) {
			continue;
		}

		for(int i = 0; i < n; i++) {
			if((as[i] & (1LL << b)) != 0) {
				as[i] = as[i] ^ v;
			}
		}

		maxi = max(maxi ^ v, maxi);
	}

	i64 ans = maxi * 2 + sum;
	printf("%lld\n", ans);

	return 0;
}
