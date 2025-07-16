#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	int LS = S.size();
	int k = 2;
	int ans = 1000;
	while (k<LS) {
		int tmp = stoi(S.substr(k-2,3));
		int l = abs(tmp-753);
		ans = min(ans, l);
		k++;
	}

	cout << ans << endl;	
	return 0;
}
