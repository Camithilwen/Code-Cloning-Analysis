#include <iostream>
using namespace std;

const int DEPTH = 17;
const int INTMAX = (1LL << 31) - 1;

struct RUQ {
	int d[1 << (DEPTH + 1)];
	int t[1 << (DEPTH + 1)];
	
	RUQ() {
		int i;
		for (i = 0; i < (1 << (DEPTH + 1)); i++) {
			d[i] = INTMAX;
			t[i] = -1;
		}
	}
	
	//[l, r)
	void update(int l, int r, int x, int Time, int a = 0, int b = (1 << DEPTH), int id = 0) {
		if (a >= r || b <= l) return;
		if (l <= a && b <= r) {
			d[id] = x;
			t[id] = Time;
			return;
		}
		update(l, r, x, Time, a, (a + b) / 2, id * 2 + 1);
		update(l, r, x, Time, (a + b) / 2, b, id * 2 + 2);
	}
	
	int getValue(int pos) {
		pos += (1 << DEPTH) - 1;
		int retD = d[pos];
		int retT = t[pos];
		
		while (pos > 0) {
			pos = (pos - 1) / 2;
			if (retT < t[pos]) {
				retT = t[pos];
				retD = d[pos];
			}
		}
		return retD;
	}
};

RUQ ruq;

int main() {
	int n, q;
	
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 0) {
			int s, t, x;
			cin >> s >> t >> x;
			ruq.update(s, t + 1, x, i);
		}
		else {
			int pos;
			cin >> pos;
			cout << ruq.getValue(pos) << endl;
		}
	}
	return 0;
}
