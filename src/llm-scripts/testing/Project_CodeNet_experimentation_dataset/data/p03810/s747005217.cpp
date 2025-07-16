#include<bits/stdc++.h>
using namespace std;

int arr[100003] , N;

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
	bool flag = 0;
	while(1){
		flag ^= 1; int cnt = 0; for(int i = 1 ; i <= N ; ++i) cnt ^= arr[i] - 1;
		if(cnt & 1){puts(!flag ? "Second" : "First"); return 0;}
		int id = 0;
		for(int i = 1 ; i <= N ; ++i)
			if(arr[i] & 1) if(arr[i] == 1 || id){puts(flag ? "Second" : "First"); return 0;} else id = i;
		--arr[id]; int Gcd = 0; for(int i = 1 ; i <= N ; ++i) Gcd = __gcd(arr[i] , Gcd);
		for(int i = 1 ; i <= N ; ++i) arr[i] /= Gcd;
	}
	return 0;
}
