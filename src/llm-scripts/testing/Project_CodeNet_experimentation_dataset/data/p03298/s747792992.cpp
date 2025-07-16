#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

short N;
ll ans = 0;
string L, R, b, r;
map<pair<string, string>, int> M;

void aff(vector<bool>&vec, short i) {
	if (i == N) {
		for (short j = 0;j < N;j++) {
			if (vec[j])b.push_back(L[j]);
			else r.push_back(L[j]);
		}
		b += 'B';
		r += 'R';
		if (M.find({ b,r }) != M.end()) {
			M.at({ b,r })++;
		}
		else {
			M.insert({ {b,r},1 });
		}
		b = "";
		r = "";
		return;
	}
	aff(vec, i + 1);
	vec[i] = 1;
	aff(vec, i + 1);
	vec[i] = 0;
	return;
}

void aff2(vector<bool>&vec, short i) {
	if (i == N) {
		for (short j = 0;j < N;j++) {
			if (vec[j])b.push_back(R[j]);
			else r.push_back(R[j]);
		}
		b += 'B';
		r += 'R';
		if (M.find({ b, r }) != M.end()) {
			ans += (ll)M.at({ b,r });
			//cout << b << " " << r << endl;
			//cout << ans << endl;
		}
		b = "";
		r = "";
		return;
	}
	aff2(vec, i + 1);
	vec[i] = 1;
	aff2(vec, i + 1);
	vec[i] = 0;
	return;
}

int main(){
	cin >> N;
	string S;
	cin >> S;
	for (short i = 0;i < N;i++) {
		L += S[i];
	}
	for (short i = 0;i < N;i++) {
		R += S[i + N];
	}
	reverse(R.begin(), R.end());
	vector<bool> vec(N, false);
	aff(vec, 0);
	aff2(vec, 0);
	cout << ans << endl;
}