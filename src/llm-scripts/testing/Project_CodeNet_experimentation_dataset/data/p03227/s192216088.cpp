#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	string s;
	cin >> s;

	if(s.length()==2){
		cout << s << endl;
	}else{
		cout << s[2] << s[1] << s[0] << endl;
	}

	return 0;
}
