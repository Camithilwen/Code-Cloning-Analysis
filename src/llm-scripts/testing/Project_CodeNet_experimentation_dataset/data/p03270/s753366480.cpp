#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int sum(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}
int mul(int a, int b) {
    return (1LL*a*b)%MOD;
}
int pw(int a, int b) {
	if (!b) return 1;
	int r = pw(a, b/2);
	r = mul(r, r);
	if (b%2) r = mul(r, a);
	return r;
}

const int MAXX = 4007;
int fact[MAXX], ifact[MAXX];

int nCr(int n, int r) {
    if (r < 0 || n < r) return 0;
    return mul(fact[n], mul(ifact[r], ifact[n-r]));
}

int split(int elements, int buckets) {
    return nCr(elements+buckets-1, buckets-1);
}

int p2[MAXX];
int ans[MAXX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < MAXX; i++)      fact[i] = mul(i, fact[i-1]);
    ifact[MAXX-1] = pw(fact[MAXX-1], MOD-2);
    for (int i = MAXX-2; i >= 0; i--)   ifact[i] = mul(i+1, ifact[i+1]);
    p2[0] = 1;
    for (int i = 1; i < MAXX; i++) p2[i] = mul(p2[i-1], 2);

    int k, n;
    cin >> k >> n;

    for (int i = 3; i <= k+1; i += 2) {
        int have = i/2;
        for (int bam = 0; bam <= have && bam <= n; bam++) {
            int tmp = mul(nCr(have, bam), p2[bam]);
            tmp = mul(tmp, split(n-bam, k-have*2+bam));
            ans[i] = sum(ans[i], tmp);
//            cout << "bam: " << bam << " -> " << tmp << endl;
        }
//        cout << "ans[" << i << "] = " << ans[i] << endl;
    }

    for (int i = 2; i <= k+1; i += 2) {
        int have = i/2 - 1;
        for (int bam = 0; bam <= have && bam <= n; bam++) {
            int tmp = mul(nCr(have, bam), p2[bam]);
            int z = split(n-bam, k-have*2+bam-1);
            if (bam < n) {
                z = sum(z, split(n-bam-1, k-have*2+bam-1));
            }
            ans[i] = sum(ans[i], mul(tmp, z));
        }
//        cout << "ans[" << i << "] = " << ans[i] << endl;
    }

//    for (int i = 2; i <= k+k; i++) cout << ans[i] << "\n";

    for (int i = 2; i <= k+1; i++)    cout << ans[i] << "\n";
    for (int i = k; i >= 2; i--)  cout << ans[i] << "\n";


    return 0;
}
