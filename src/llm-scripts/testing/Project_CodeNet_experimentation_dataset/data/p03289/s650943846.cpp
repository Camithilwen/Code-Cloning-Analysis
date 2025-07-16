#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	string s;
	cin >> s;
	bool OK_A = false;
	bool OK_C = false;
	bool OK_lower = true;
	int cnum;

	if(s[0] == 'A') OK_A = true;
	rep(i, s.size()-1){
		if(i != 1){
			if(s[i] == 'C'){
				cnum = i;
				if(OK_C == false) OK_C = true;
				else OK_C = false;
			}
		}
	}

	rep(i, s.size()){
		if(i != 0 && i != cnum){
			if(isupper(s[i])) OK_lower = false;
		}
	}

	if(OK_A && OK_C && OK_lower) cout << "AC" << endl;
	else cout << "WA" << endl;
    return 0;
}