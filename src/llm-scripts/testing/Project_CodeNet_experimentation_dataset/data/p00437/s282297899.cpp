#include<iostream>
#include<cstdio>
using namespace std;
int A, B, C, N;
int X[300];
int I[1000], J[1000], K[1000], L[1000];
int main()
{
	while (true){
		scanf("%d%d%d", &A, &B, &C);
		if (A == 0 && B == 0 && C == 0)return 0;
		scanf("%d", &N);
		for (int i = 0; i < A + B + C; i++)X[i] = 2;
		for (int i = 0; i < N; i++){
			scanf("%d%d%d%d", &I[i], &J[i], &K[i], &L[i]);
			I[i]--; J[i]--; K[i]--;
		}
		for (int CC = 0; CC < N; CC++){
			for (int i = 0; i < N; i++){
				if (L[i] == 1){
					X[I[i]] = 1;
					X[J[i]] = 1;
					X[K[i]] = 1;
				}
				else{
					if (X[I[i]] == 1 && X[J[i]] == 1)X[K[i]] = 0;
					if (X[J[i]] == 1 && X[K[i]] == 1)X[I[i]] = 0;
					if (X[K[i]] == 1 && X[I[i]] == 1)X[J[i]] = 0;
				}
			}
		}
		for (int i = 0; i < A + B + C; i++){
			printf("%d\n", X[i]);
		}
	}
}