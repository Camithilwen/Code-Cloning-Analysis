#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int X, Y;
	scanf("%d %d", &X, &Y);
	int award[] = {300000, 200000, 100000, 0};
	if (X == 1 && Y == 1) printf("1000000\n");
	else printf("%d\n", award[min(3, X - 1)] + award[min(3, Y - 1)]);
	return 0;
}
