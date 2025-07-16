#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
int main() {
	int i, d;
	cin >> n >> m;
	for(i=1, d=m; d>0; i++, d-=2) printf("%d %d\n", i, i+d);
	for(i=m+2, d=m-1; d>0; i++, d-=2) printf("%d %d\n", i, i+d);
	return 0;
}