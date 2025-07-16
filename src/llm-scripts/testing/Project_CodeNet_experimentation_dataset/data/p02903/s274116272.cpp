#include <bits/stdc++.h>
using namespace std;

int main(){
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	for (int i=0; i<h; i++){
		for (int j=0; j<w; j++){
			if ((i<b && j<a) || (i>=b && j>=a)) cout << "1";
			else cout << "0";
		}
		cout << "\n";
	}
}