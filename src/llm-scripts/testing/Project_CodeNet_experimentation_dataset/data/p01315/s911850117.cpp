#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, string> pds;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

bool cmp(pds a, pds b) {
	return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first);
}

int main() {
	for (int N; cin >> N&&N;) {
		vector<pds> p;
		for (int i = 0; i < N; i++) {
			string L; int P, A, B, C, D, E, F, S, M;
			cin >> L >> P >> A >> B >> C >> D >> E >> F >> S >> M;
			int Q = (S*F)*M;
			double cp = (double)(Q - P) / (A + B + C + (D + E)*M);
			p.push_back(pds(cp, L));
		}
		sort(p.begin(), p.end(), cmp);
		for (int i = 0; i < p.size(); i++) {
			cout << p[i].second /*<< " " << p[i].first*/ << endl;
		}
		cout << "#" << endl;
	}
	return 0;
}