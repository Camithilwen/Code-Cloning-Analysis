#include <cstdio>
const int N = 1000064;
int A[N], B[4];
int main() {
	int m, x, *a = A, *b = B;
	scanf("%*d%d",&m);
	if (m == 1) {
		scanf("%d",&x);
		if (x == 1) puts("1\n1\n1");
		else printf("%d\n2\n1 %d",x,x-1);
		return 0;
	}
	while (m--) {
		scanf("%d",&x);
		*(x&1 ? b : a)++ = x;
		if (b > B+2) {puts("Impossible"); return 0;}
	}
	while (b != B+2) *b++ = *--a;
	printf("%d ",B[1]);
	for (int *i = a; i != A;) printf("%d ",*--i);
	printf("%d\n%d\n%d",*B,int(a-A)+1+(*B>1),B[1]+1);
	for (int *i = a; i != A;) printf(" %d",*--i);
	if (--*B) printf(" %d",*B);
	return 0;
}