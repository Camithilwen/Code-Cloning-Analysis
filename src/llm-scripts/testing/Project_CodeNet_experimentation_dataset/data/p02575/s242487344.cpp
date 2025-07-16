#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int H, W;
int A[200005], B[200005];

int C[200005];
set<int > S;

int ans[200005];

multiset<int> M;

int p = 0;
int E[200005];

void ADD(int k) {
	E[k]++;
}
void DEL(int k) {
	E[k]--;
	
	while (E[p] == 0) { p++; }
}

int main(void) {

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		cin >> A[i] >> B[i];
	}

	for (int i = 1; i <= W; i++) { S.insert(i); M.insert(0); /*ADD(0);*/ }
	
	/*if (A[1] == 1 && B[1] == W) { for (int i = 1; i <= H; i++) { cout << -1 << endl; } return 0; }

	if (A[1]==1) {}
	else if (A[1] == 2) { S.insert(1); M.insert(0); }
	else { S.insert(1); M.insert(0);  S.insert(A[1] - 1); M.insert(0); }

	if (B[1] < W) {
		S.insert(B[1] + 1); M.insert(0);
	}
	ans[1] = 1;*/
	
	for (int i = 1; i <= H; i++) {
		
		//cout << "i= " << i << endl;

		//-----------------
		auto it = S.upper_bound(B[i] + 1);
		//auto  it = upper_bound(S.begin(), S.end(), B[i] + 1);
		if (it != S.begin()) { --it; }
		if (it!=S.end() && *it <= B[i] + 1 && ( B[i]+1<=W)) {
			C[B[i] + 1] = C[*it] + B[i] + 1 - (*it); 

			if (S.find(B[i] + 1) != S.end()) {
				auto itr = M.find(C[B[i] + 1]);  M.erase(itr);
			}
			S.insert(B[i] + 1);  M.insert(C[B[i] + 1]); 
		}

		//cout << "S: "; for (auto y : S) { cout << " " << y; }cout << endl;
		//cout << "M: "; for (auto y : M) { cout << " " << y; }cout << endl;

		//--------------------------------------------------------
		
		it = S.upper_bound(A[i] - 1);
		//it = upper_bound(S.begin(), S.end(), A[i] - 1);
		if (it != S.begin()) { --it; }
		if (it!=S.end() && *it <= A[i] - 1  &&  A[i]-1>=1) {
			C[A[i] - 1] = C[*it] + A[i] - 1 - (*it);
			if (S.find(A[i] - 1) != S.end()) { 
				auto itr = M.find(C[A[i]-1]);  M.erase(itr);                              
			}
			S.insert(A[i] - 1); M.insert(C[A[i] - 1]);
		}

		//cout << "S: "; for (auto y : S) { cout << " " << y; }cout << endl;
		//cout << "M: "; for (auto y : M) { cout << " " << y; }cout << endl;
		
		//--------------------------------

		it = S.lower_bound(A[i]);
		//it = lower_bound(S.begin(), S.end(), A[i]);
		while (it!=S.end() && *it <= B[i]) {
			auto itr = M.find(C[*it]); //cout << *itr << " 消去" << endl;
			M.erase(itr); 
			//DEL(C[*it]);
			 S.erase(it++);
		}

		//cout << "S: "; for (auto y : S) { cout << " " << y; }cout << endl;
		//cout << "M: "; for (auto y : M) { cout << " " << y; }cout << endl;

		//cout << "i= " << i << endl;
		//cout << "E:"; for (int i = 0; i <= 10; i++) { cout << " " << E[i]; } cout << " p= " << p << endl;

		if (S.size() == 0) { ans[i] = -1; }
		else { ans[i] = i + *M.begin()/*p*/; }

	}

	
	for (int i = 1; i <= H; i++) {
		printf("%d\n", ans[i]);
		//cout << ans[i] << endl;
	}

	return 0;
}