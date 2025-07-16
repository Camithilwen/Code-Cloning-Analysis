#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

struct Dice {
	int d[6], E, S, U;
	void init(int a[]) {
		rep(i, 6)d[i] = a[i];
		E = 2; S = 1; U = 0;
	}
	void rotate(char C) {
		int a = E, b = S, c = U;
		switch (C) {
		case'E':E = U; U = 5 - a; break;
		case'N':U = S; S = 5 - c; break;
		case'S':S = U; U = 5 - b; break;
		case'W':U = E; E = 5 - c; break;
		case'R':S = E; E = 5 - b; break;
		case'L':E = S; S = 5 - a; break;
		}
	}
	int rotate(int a, int b) {
		rep(k, 2) {
			rep(i, 4) {
				rep(j, 4) {
					if (a == d[U] && b == d[S])return d[E];
					rotate('E');
				}
				rotate('S');
			}
			rotate('L');
		}
	}
	bool operator==(Dice b) {
		rep(k, 2) {
			rep(i, 4) {
				rep(j, 4) {
					if (b.d[b.U] == d[U] && b.d[b.S] == d[S] && b.d[b.E] == d[E] &&
						b.d[5 - b.U] == d[5 - U] && b.d[5 - b.S] == d[5 - S] && b.d[5 - b.E] == d[5 - E])
						return true;
					rotate('E');
				}
				rotate('S');
			}
			rotate('L');
		}
		return false;
	}
};
Dice d[100]; int a[100][6];
int main() {
	int n; cin >> n;
	rep(i, n) {
		rep(j, 6)cin >> a[i][j];
		d[i].init(a[i]);
	}
	rep(i, n)for (int j = i + 1; j < n; j++) {
		if (d[i] == d[j]) {
			puts("No"); return 0;
		}
	}
	puts("Yes");
}