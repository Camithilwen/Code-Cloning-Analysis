#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main() {
	string s;
	cin >> s;
	if(s[0] != 'A' || isupper(s[1]) || isupper(s[s.size() - 1])){
		cout << "WA" << endl;
		return 0;
	}
	bool isFoundC = false;
	for(int i = 2; i < s.size() - 1; i++){
		if(!isFoundC && s[i] == 'C') isFoundC = true;
		else if(s[i] == 'C'){
			cout << "WA" << endl;
			return 0;
		}else if(isupper(s[i])){
			cout << "WA" << endl;
			return 0;
		}
	}
	cout << (isFoundC ? "AC" : "WA") << endl;
}
