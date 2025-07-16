#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

inline void reset(int cnt[], int& state) {
	REP(i, 3) cnt[i] = 0;
	state = 0;
}

int main() {
	int ans = 0, cnt[3], state;
	char JOI[] = {'J', 'O', 'I'};

	reset(cnt, state);
	while (1) {
		int c = getchar();

		if (c == JOI[state]) {
			cnt[state]++;
		} else {
			if (state == 2) {
				if (cnt[1] <= min(cnt[0], cnt[2]))
					ans = max(ans, cnt[1]);
				reset(cnt, state);
			} else if (c == JOI[state + 1]) {
				state++;
			} else
				reset(cnt, state);

			if (c == JOI[state]) cnt[state]++;
		}

		if (c == '\n') break;
	}
	cout << ans << endl;

	return 0;
}