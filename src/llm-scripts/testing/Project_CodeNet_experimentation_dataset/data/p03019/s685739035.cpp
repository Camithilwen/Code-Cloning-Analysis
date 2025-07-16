#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, maxi;
int aoki[100005], lo[100005], up[100005];
long long score[100005];
bool higher[100005];

long long require;
long long ans, ans1, ans2;

vector<pair<long long, int> > chase;

int main(){
	scanf("%d %d", &n, &maxi);
	for(int i = 1; i <= n; i++){
		scanf("%d %d %d", &aoki[i], &lo[i], &up[i]);
		require += 1LL * aoki[i] * lo[i];
		score[i] = 1LL * aoki[i] * lo[i] + 1LL * (maxi - aoki[i]) * up[i];
		chase.push_back({-score[i], i});
	}
	sort(chase.begin(), chase.end());
	for(auto choice: chase){
		long long delta = choice.first;
		int id = choice.second;
		if(require + delta <= 0){
			// two scenarios
			// scenario 1: pick all "higher", one partial from "lower" ones
			int opt = maxi;
			for(int i = 1; i <= n; i++){
				if(!higher[i]){
					// see if it can make up the difference of delta
					if(score[i] < require){
						continue;
					}else if(1LL * aoki[i] * lo[i] >= require){
						opt = min(opt, (int)ceil((require + .0) / lo[i]));
					}else{
						opt = min(opt, aoki[i] + (int)ceil((require - 1.0 * aoki[i] * lo[i]) / up[i]));
					}
				}
			}
			ans1 = ans + opt;
			// scenario 2: pick all "higher" and this, then make one "higher" partial
			higher[id] = true;
			require += delta;
			opt = maxi;
			for(int i = 1; i <= n; i++){
				if(higher[i]){
					long long target = require + score[i]; // should be positive
					if(1LL * aoki[i] * lo[i] >= target){
						opt = min(opt, (int)ceil((target + .0) / lo[i]));
					}else{
						opt = min(opt, aoki[i] + (int)ceil((target - 1.0 * aoki[i] * lo[i]) / up[i]));
					}
				}
			}
			ans2 = ans + opt;
			printf("%lld\n", min(ans1, ans2));
			return 0;
		}
		higher[id] = true;
		require += delta;
		ans += maxi;
	}
	return 0;
}