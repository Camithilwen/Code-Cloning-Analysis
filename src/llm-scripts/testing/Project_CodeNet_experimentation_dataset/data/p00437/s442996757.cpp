#include<bits/stdc++.h>
using namespace std;

struct parts{int power; int motor; int cable; int pass;};

int main(){
	int a, b, c;
	int N;
	int is_disorder[300];
	parts result[1000];	
	for(;;){
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0) break;
		for(int i = 0; i < a + b + c; i++) is_disorder[i] = 2;
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> result[i].power >> result[i].motor >> result[i].cable >> result[i].pass;
			result[i].power--; result[i].motor--; result[i].cable--;
			if(result[i].pass == 1){
				is_disorder[result[i].power] = 1;
				is_disorder[result[i].motor] = 1;
				is_disorder[result[i].cable] = 1;
			}
		}
		for(int i = 0; i < N; i++){
			if(result[i].pass == 0){
				if(is_disorder[result[i].power] == 1 && is_disorder[result[i].motor] == 1) is_disorder[result[i].cable] = 0;
				if(is_disorder[result[i].power] == 1 && is_disorder[result[i].cable] == 1) is_disorder[result[i].motor] = 0;
				if(is_disorder[result[i].motor] == 1 && is_disorder[result[i].cable] == 1) is_disorder[result[i].power] = 0;
			}
		}
		for(int i = 0; i < a + b + c; i++){
			cout << is_disorder[i] << endl;
		}
	}
	return 0;
}