#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define for_rev(i,a,b) for(int i=a;i>=b;--i)
#define allof(a) a.begin(),a.end()
#define minit(a,b) memset(a,b,sizeof(a))
#define size_of(a) (int)a.size()

int N, M;
int p[1010];

int main() {
	while (cin >> N >> M, N) {
		for_(i,0,N) cin >> p[i];
	
		vector<int> vp;
		vp.push_back(0);
		for_(i,0,N) vp.push_back(p[i]);
	
		vector<int> sum2;
		for_(i,0,N + 1) for_(j,0,N + 1) sum2.push_back(vp[i] + vp[j]);
	
		sort(allof(sum2));
		int s_size = size_of(sum2);
		int ans = 0;
		for_(i,0,s_size) {
			int sum = sum2[i];
			if (sum <= M) {
				int sub = M - sum;
				int lb = *(upper_bound(allof(sum2), sub) - 1);
				//cout << sub << " " << lb << endl;
				sum += lb;
				ans = max(ans, sum);
			}
		}
		cout << ans << endl;
	}
	return 0;
}