#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){

	int a, b, maior, res = 0;
	cin >> a >> b;

	rep(i,2){

		if (a > b){

			maior = a;
			a--;

		}else{

			maior = b;
			b--;
		}

		res += maior;
	}
	cout << res;
}