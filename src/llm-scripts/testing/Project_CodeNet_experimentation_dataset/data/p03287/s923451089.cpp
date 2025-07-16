#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <map>
using namespace std;

long long A[100002] = {0};
long long  S[100002] = {0};
map<long long, long long> m;

int main(int argc, char* argv[]){
	int N;
	long long M; //N 1.. 100000 M 2..1000000000 

	cin >> N >> M ;

	A[0] = 0, S[0] = 0;
	for(int i=1; i<=N; i++){
		cin >> A[i];
		S[i] = ( S[i-1]+A[i] ) % M;
		if(m.count(S[i])==0){
			m[S[i]] = 1;
		}
		else{
			long long r = m[S[i]];
			m[S[i]] = r+1;
		}
	}

	unsigned long long ans = 0;
	for(auto it=m.begin(); it!=m.end(); ++it){
		long long k, v;
		k = it->first;
		v = it->second;
		if(k==0){
			ans = ans + v + (v*(v-1))/2; //重複OK
		}
		else{
			ans = ans + (v*(v-1))/2;
		}
	}
	printf("%llu\n", ans);
	return 0;
}