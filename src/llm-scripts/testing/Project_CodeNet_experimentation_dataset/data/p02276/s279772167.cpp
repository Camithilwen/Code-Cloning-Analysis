#include <iostream>
#include <cstdio>
using namespace std;

int A[100000], n;

int Partition(int p, int r){
	int x = A[r - 1], j = 0;
	//printf("%d ", A[r - 1]);
	for(int i = 0;i < n;i++){
		if(A[i] <= x){
			int tmp = A[j];
			A[j++] = A[i];
			A[i] = tmp;
		}
	}
	return j - 1;
}

main(){
    scanf("%d", &n);
    for(int i = 0;i < n;i++)scanf("%d", &A[i]);
	int j = Partition(0, n);
	for(int i = 0;i < n - 1;i++){
		if(i)printf(" ");
		if(i == j)printf("[");
		printf("%d", A[i]);
		if(i == j)printf("]");
	}
	printf(" %d\n", A[n - 1]);
}