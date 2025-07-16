#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

int N, M;



int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	while (N) {
		int num[1001];
		int ans = 0;
		set<int>F;
		set<int>S;
		for (int i = 0; i < N; i++)cin >> num[i];
		F.insert(0);
		for (int i = 0; i < N/2; i++) {
			F.insert(num[i]);
			for (int j = 0; j < N/2; j++) {
				F.insert(num[i] + num[j]);
			}
		}
		S.insert(0);
		for (int i = N/2; i < N; i++) {
			S.insert(num[i]);
			for (int j = N/2; j < N; j++) {
				S.insert(num[i] + num[j]);
			}
		}
		set<int>::reverse_iterator ritr = S.rbegin();
		for (auto i : F) {
			if (ritr == S.rend())break;
			while ((i + *ritr) > M) {
				++ritr;
				if (ritr ==S.rend())break;
			}
			if(ritr!=S.rend())	ans = max(ans, i + *ritr);
		}
		cout << ans << endl;
		cin >> N >> M;
	}
	return 0;
}