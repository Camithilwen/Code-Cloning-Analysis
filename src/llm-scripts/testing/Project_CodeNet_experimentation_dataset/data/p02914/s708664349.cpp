#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int N;
long long A[MAXN], B[MAXN];

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%lld", &A[i]);
		B[i] = A[i];
	}
	
	long long r1 = 0, r2 = 0;
	for(int i = 59, k = 0; i >= 0; i--){
		int ind = -1, p = 0;
		
		for(int j = 0; j < N; j++)if(B[j] & (1LL << i))
			p ^= 1;
		
		for(int j = k; j < N; j++)if(A[j] & (1LL << i)){
			ind = j;
			break;
		}
		
		if(p == 1){
			r1 += 1LL << i;
			continue;
		}
		if(ind == -1)continue;
		
		swap(A[ind], A[k]);
		if(!(r2 & (1LL << i)))r2 ^= A[k];
		
		for(int j = k + 1; j < N; j++)
			if(A[j] & (1LL << i))A[j] ^= A[k];
		
		k++;
	}
	r2 &= ~r1;
	
	printf("%lld\n", r1 + 2 * r2);
	
	return 0;
}
