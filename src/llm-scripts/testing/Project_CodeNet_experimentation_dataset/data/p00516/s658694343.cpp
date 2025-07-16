// Vote
#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
	int N, M, i, j, maxp = 0, maxs;
	scanf("%d %d", &N, &M);
	int a[N], b[M], p[N];
	for (i = 0; i < N; ++i){
		cin >> a[i];
		p[i] = 0;
	}
	for (j = 0; j < M; ++j){
		cin >> b[j];
	}
	for (j = 0; j < M; ++j){
		for (i = 0; i < N; ++i){
			if (a[i] <= b[j]){
				p[i]++;
				break;
			}
		}
	}
	for (i = 0; i < N; ++i){
		if (p[i] > maxp){
			maxp = p[i];
			maxs = i+1;
		}
	}
	cout << maxs << endl;
	return 0;
}