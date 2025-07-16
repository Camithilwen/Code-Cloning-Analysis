#include <iostream>
#include <cstdio>
using namespace std;

int a[11][11];

void init(int n) {
  for(int i = 0; i <= n; ++i) {
	a[i][n] = 0;
	a[n][i] = 0;
  }
}

void Comp(int n) {
  for(int i = 0; i < n; ++i) {
	for(int j = 0; j < n; ++j) {
	  a[i][n] += a[i][j];
	  a[n][j] += a[i][j];
	  a[n][n] += a[i][j];
	}
  }
}

void print(int n) {
  for(int i = 0; i <= n; ++i) {
	for(int j = 0; j <= n; ++j) {
	  printf("%5d", a[i][j]);
	}
	printf("\n");
  }
}

int main() {
  int n;
  
  while(scanf("%d", &n)) {
	if(n == 0) break;

	init(n);
	for(int i = 0; i < n; ++i) {
	  for(int j = 0; j < n; ++j) {
		cin >> a[i][j];
	  }
	}
	Comp(n);
	print(n);
  }
  return 0;
}