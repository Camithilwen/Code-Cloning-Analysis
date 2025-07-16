#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B;
	scanf("%d%d", &A, &B);
	printf("%d\n", (A == B) ? (A + B) : (2 * max(A, B) - 1));
	return 0;
}