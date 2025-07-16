#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mxn = 11;
vector<bool> val(mxn, 1);

bool valid(string s){
	bool ok = 1;
	int n = int(s.size());
	for(int i = 0; i < n && ok; ++i){
		ok &= (val[s[i] - '0']);
	}
	return ok;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 0, x; i < k; ++i){
		cin >> x;
		val[x] = 0;
	}	
	while(1){
		string s = to_string(n);	
		if(valid(s)){
			break;
		}
		++n;
	}
	cout << n << '\n';
	return 0;
}