#include<cstdio>
#include <iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>

#define rep(i,n) for(int i=0; i<int(n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

string name, str;
int length1, length2;

struct list {
	int a;
	int b;
	int c;
	int r;
};

int ok[1010];

int main() {
	while (1) {
		int A, B, C, N;
		cin >> A >> B >> C;
		if (A == 0 && B == 0 && C == 0)break;
		cin >> N;

		for (int i = 0; i < A + B + C; i++)
			ok[i] = 2;

		struct list d[1010];

		for (int i = 0; i < N; i++) {
			cin >> d[i].a >> d[i].b >> d[i].c >> d[i].r;
			if (d[i].r) {
				ok[d[i].a - 1] = 1;
				ok[d[i].b - 1] = 1;
				ok[d[i].c - 1] = 1;
			}
		}
		for (int i = 0; i < N; i++) {
			if (d[i].r != 1) {
				if (ok[d[i].a - 1] == 1 && ok[d[i].b - 1] == 1)
					ok[d[i].c - 1] = 0;
				else if (ok[d[i].b - 1] == 1 && ok[d[i].c - 1] == 1)
					ok[d[i].a - 1] = 0;
				else if (ok[d[i].a - 1] == 1 && ok[d[i].c - 1] == 1)
					ok[d[i].b - 1] = 0;
			}
		}
		for (int i = 0; i < A + B + C; i++)
			cout << ok[i] << endl;
	}
	return 0;
}