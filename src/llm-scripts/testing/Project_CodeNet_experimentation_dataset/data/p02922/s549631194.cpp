#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	for(int i=0;;++i){
		int ans = 1 + (a - 1)*i;
		if(b <= ans){
			cout << i;
			return 0;
		}	
	}
}
