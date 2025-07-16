#include "bits/stdc++.h"
#include <unordered_set>

#define REP(i, n) for(decltype(n) i = 0; i < (n); i++)
#define REP2(i, x, n) for(decltype(x) i = (x); i < (n); i++)
#define REP3(i, x, n) for(decltype(x) i = (x); i <= (n); i++)
#define RREP(i, n) for (decltype(n) i = (n) - 1; i >= 0; i--)

#define ALL(a) (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

#define LL long long int
#define LD long double

#define INF 1000000000
#define PI 3.14159265358979323846

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// N, E, S, W
const int dx[4] = { -1, 0,  1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<LL> vll;

//==============================================
vi A, G;

int cnt = 0;
int gSize;

void insertionSort(int n,int g) {
	REP2(i, g, n) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(int n) {
	int h = 1;
	while (h <= n) {
		G.push_back(h);
		h = 3 * h + 1;
	}
	gSize = G.size();

	RREP(i, gSize) {
		insertionSort(n, G[i]);
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int tmp;
	REP(i, n) cin >> tmp, A.push_back(tmp);

	shellSort(n);

	cout << gSize << "\n";
	RREP(i, gSize) {
		cout << G[i];
		if (i)cout << " ";
	}
	cout << "\n";
	cout << cnt << "\n";

	REP(i, n) {
		cout << A[i] << "\n";
	}
	return 0;
}