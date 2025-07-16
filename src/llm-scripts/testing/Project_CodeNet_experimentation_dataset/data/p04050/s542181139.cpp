#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T> inline void getint(T &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, M, A[100005], cnt = 0;

int main(){
	getint(N), getint(M);
	for(register int i = 1; i <= M; i++) getint(A[i]);
	for(register int i = 1; i <= M; i++) if(A[i] & 1){
		if(++cnt == 1) swap(A[i], A[1]);
		else if(cnt == 2) swap(A[i], A[2]);
		else return puts("Impossible"), 0;
	}
	if(cnt) swap(A[cnt], A[M]);
	for(register int i = 1; i <= M; i++) printf("%d ", A[i]); puts("");
	if(cnt <= 1){
		printf("%d\n1 ", A[M] == 1 ? M : M + 1);
		for(register int i = 1; i < M; i++) printf("%d ", A[i]);
		if(A[M] > 1) printf("%d\n", A[M] - 1);
	}
	else{
		printf("%d\n%d ", A[M] == 1 ? M - 1 : M, A[1] + 1);
		for(register int i = 2; i < M; i++) printf("%d ", A[i]);
		if(A[M] > 1) printf("%d\n", A[M] - 1);
	}
	return 0;
}