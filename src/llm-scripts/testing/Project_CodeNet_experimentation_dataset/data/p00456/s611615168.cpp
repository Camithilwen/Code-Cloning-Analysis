#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int W[10], K[10];
	
	for(int i = 0; i < 10; i++) scanf("%d", &W[i]);
	for(int i = 0; i < 10; i++) scanf("%d", &K[i]);
	
	sort(W, W + 10);
	sort(K, K + 10);
	
	printf("%d %d\n", W[9] + W[8] + W[7], K[9] + K[8] + K[7]);
	
	return 0;
}