/*First observation is that little numbers should be summed up to go to above 3
 * any number above 3 is better multiplied
 * also given a set of numbers to add, the best pairs to pick are least with most since we will multiply them next
 * also if the number of numbers we are going to add is N
 * then the numbers we will add are the first N numbers given that the array is sorted
 * so we just bruteforce on N
 *
 */

#include <bits/stdc++.h>
#include <complex>

using namespace std;
typedef long long int ll;

const double PI = acos(-1);
const int N = 2e6, MOD = 1e6 + 3, LOG = 21;

ll k, mvup, toAdd;
bool chn = false;
vector<ll> v;

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%lld", &k);
	while (k % 50 != 0) {
		k++;
		mvup++;
	}
	ll N = 50;
	ll base = N - 1;
	ll needed = k / N;
	printf("%lld\n", N);
	for (int i = 0; i < N; i++) {
		v.push_back(base + needed);
	}
	toAdd = mvup;
	for (int i = 0; i < N; i++) {
		if (mvup) {
			v[i] -= N;
			mvup--;
			v[i] += (toAdd - 1);
		} else {
			v[i] += toAdd;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%lld ", v[i]);
	}
	return 0;
}
