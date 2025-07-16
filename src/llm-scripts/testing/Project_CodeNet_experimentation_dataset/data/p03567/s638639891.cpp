#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define Cout(s) cout << s << endl
string Yes(bool b) {if(b){return "Yes";} else {return "No";}}
string YES(bool b) {if(b){return "YES";} else {return "NO";}}


int main(){
	string S;
	cin >> S;
	string T = "AC";
	bool ok = false;
	rep(i, S.size()-1){
		string s = S.substr(i, 2);
		if(s == T) ok = true; 
	}

	Cout(Yes(ok));
}
