#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	int a,b,c;

	cin >> a >> b >> c;
	
	if(a<c){
		if(c<b) cout << "Yes" << endl;
		else cout << "No" << endl;
	}else{
		if(c>b) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
