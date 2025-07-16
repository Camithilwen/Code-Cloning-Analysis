#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 12

char A[SIZE],B[SIZE],C[SIZE];


int main(){

	scanf("%s %s %s",A,B,C);

	char last_a,last_b;
	for(int i = 0; A[i] != '\0'; i++){

		last_a = A[i];
	}
	for(int i = 0; B[i] != '\0'; i++){

		last_b = B[i];
	}

	if(last_a == B[0] && last_b == C[0]){

		printf("YES\n");

	}else{

		printf("NO\n");
	}

	return 0;
}
