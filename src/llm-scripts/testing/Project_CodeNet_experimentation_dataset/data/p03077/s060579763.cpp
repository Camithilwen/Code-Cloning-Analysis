#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	LL n,a[5];
	// nyuryoku
	cin >> n >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	// keisan
	LL ans = 4;
	LL plus = 0;
	if(n%a[0] == 0){
		plus = n/a[0];
	}else{
		plus = n/a[0] + 1;
	}
	for(int i=1;i<5;i++){
		if(n%a[i] == 0){
			plus = max(plus,n/a[i]);
		}else{
			plus = max(plus,n/a[i] + 1);
		}
	}
	// syutsuryoku
	cout << plus + ans << endl;
}