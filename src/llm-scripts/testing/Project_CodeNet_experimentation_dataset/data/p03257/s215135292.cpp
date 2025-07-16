#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "complex"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 1e-8;


long long int N, M, K, H, W, L, R;

list<int> Prime(int num) {
	list<int>P;
	for (int i = 5; i <= num; i += 6) {
		bool flag = true;
		for (auto j : P) {
			if (j*j > i) {
				break;
			}
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i);
		flag = true;
		for (auto j : P) {
			if (j*j > i + 2) {
				break;
			}
			if ((i + 2) % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i + 2);
	}
	P.push_front(3);
	P.push_front(2);
	return P;
}

inline long long int gcd(long long int a, long long int b) {
	if (a < b)a ^= b ^= a ^= b;
	while (b) {
		a %= b;
		a ^= b ^= a ^= b;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	auto P = Prime(10000);
	list<int>p;
	P.pop_front();
	while (p.size() < N + 2) {
		p.push_back(P.front());
		P.pop_front();
	}
	vector<int>tate((N+2)/2);
	vector<int>yoko((N+2)/2);
	for (int i = 0; i < (N + 2) / 2; i++) {
		if (i % 2) {
			tate[i] = p.front();
			p.pop_front();
		}
		else {
			tate[i] = p.back();
			p.pop_back();
		}
	}
	for (int i = 0; i < N/2+1; i++) {
		if (i % 2) {
			yoko[i] = p.front();
			p.pop_front();
		}
		else {
			yoko[i] = p.back();
			p.pop_back();
		}
	}
	vector<vector<long long int>>v(N, vector<long long int>(N));
	map<long long int, int>m;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i^j) & 1) {
				v[i][j] = tate[i / 2] * yoko[j / 2] * 2;
				if (m[v[i][j]])v[i][j] *= 2;
				m[v[i][j]]++;
			}
		}
	}
	int dir[] = { 0,1,0,-1,0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!v[i][j]) {
				v[i][j] = 1;
				for (int k = 0; k < 4; k++) {
					int ny = i + dir[k];
					int nx = j + dir[k + 1];
					if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
					v[i][j] = v[i][j] / gcd(v[i][j], v[ny][nx])*v[ny][nx];
				}
				v[i][j]++;
				if (m[v[i][j]])v[i][j] = v[i][j] * 2 - 1;
				m[v[i][j]]++;
			}
		}
	}
	long long int mx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j)cout << " ";
			cout << v[i][j];
			mx = max(mx, v[i][j]);
		}
		cout << endl;
	}
	return 0;
}