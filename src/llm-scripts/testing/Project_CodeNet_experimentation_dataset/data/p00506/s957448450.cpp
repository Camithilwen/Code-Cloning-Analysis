#include<iostream>
#include<algorithm>

using namespace std;


int main(void){

	int n;
	int a, b, c;
	int mn;
	cin >> n;

	if (n == 2){
		cin >> a >> b;
		mn = min(a, b);
	}
	else{
		cin >> a >> b >> c;
		mn = min(a, min(b, c));
	}

	for (int i = 1; i <= mn; i++){
		if (n == 2){
			if (a%i == 0 && b%i == 0) cout << i << endl;
		}
		else if (a%i == 0 && b%i == 0 && c%i == 0) cout << i << endl;
	}
	return 0;
}