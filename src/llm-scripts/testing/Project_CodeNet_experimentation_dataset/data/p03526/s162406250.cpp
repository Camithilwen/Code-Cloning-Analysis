#include <iostream>
#include <utility>
#include <algorithm>
typedef long long ll;
using namespace std;

ll H[5010], P[5010], dp[5010], lmax=1e12;
pair<pair<ll, ll>, int> pr[5010];

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		cin >> H[i] >> P[i];
		pr[i]=make_pair(make_pair(H[i]+P[i], P[i]), i);
	}
	sort(pr, pr+N);
	dp[0]=0;
	for(int i=1; i<=N+1; ++i) dp[i]=lmax;
	for(int i=0; i<N; ++i){
		int t=pr[i].second;
		for(int j=i; j>=0; --j){
			if(dp[j]<=H[t]){
				dp[j+1]=min(dp[j+1], dp[j]+P[t]);
			}
		}
	}
	int ans=0;
	while(dp[ans+1]<lmax) ++ans;
	cout << ans << endl;
	return 0;
}