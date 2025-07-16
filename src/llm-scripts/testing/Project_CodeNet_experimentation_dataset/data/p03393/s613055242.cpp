#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	lli n = s.size();
	if(s.size() == 26){
		if(s == "zyxwvutsrqponmlkjihgfedcba") cout << -1 << endl;
		else{
			string b = s;
			next_permutation(s.begin(), s.end());
			rep(i, 26){
				if(s[i] == b[i]) cout << s[i];
				else{
					cout << s[i] << endl;
					return 0;
				}
			}
		}

		return 0;
	}

	vector<bool> used(26);
	rep(i, n) used[s[i]-'a'] = true;
	rep(i, 26){
		if(used[i] == false){
			cout << s+char('a'+i) << endl;
			return 0;
		}
	}
	cout << "error" << endl;
	return 0;
}
