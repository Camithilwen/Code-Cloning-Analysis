#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s; cin >> s;

	int ans = 0;

	int cnt_J = 0;
	int cnt_O = 0;
	int cnt_I = 0;

	char p = 'X';

	for (int i = 0;i < s.size();i++){
		if(s[i] == 'J') {
			cnt_O = cnt_I = 0;
			if(p != s[i]) cnt_J = 1;
			else cnt_J++;
		} else if(s[i] == 'O') {
			if(cnt_J == 0){
				cnt_J = cnt_O = cnt_I = 0;
			} else {
				if(p == 'I') cnt_J = cnt_O = cnt_I = 0;
				else cnt_O++;
			}
		} else if(s[i] == 'I'){
			if(cnt_O == 0){
				cnt_J = cnt_O = cnt_I = 0;
			} else {
				cnt_I++;
				if(cnt_O <= cnt_J && cnt_O <= cnt_I) ans = max(cnt_O,ans);
			}
		}
		p = s[i];
	}

	cout << ans << endl;

	return 0;

}

