#include <cstdio>
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
	array<array<int,10>,2> ar;
	for(int i = 0; 2 > i; i++){
		for(int j = 0; 10 > j; j++){
			scanf("%d\n", &ar[i][j]);
		}
		sort(ar[i].begin(), ar[i].end(), [](int a, int b){return a > b;});
	}
	printf("%d %d\n", accumulate(ar[0].begin(), ar[0].begin()+3, 0), accumulate(ar[1].begin(), ar[1].begin()+3, 0));
	return 0;
}