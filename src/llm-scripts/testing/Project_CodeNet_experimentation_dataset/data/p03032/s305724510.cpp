#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;


int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}

	ll ans = 0;
	for (int all = 0; all <= min(k, n); all++){
		for (int i = 0; i <= all; i++){
			int l = i, r = all - i;
			int rem = k - all;
			priority_queue<int, vector<int>, greater<int> > que;
			for (int j = 0; j < l; j++){
				que.push(v[j]);
			}
			for (int j = 0; j < r; j++){
				que.push(v[n-j-1]);
			}
			ll tmp = 0;
			while (!que.empty()){
				if (que.top() < 0 && rem > 0){
					rem--;
					que.pop();
				}else{
					tmp += que.top();
					que.pop();
				}
			}
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}