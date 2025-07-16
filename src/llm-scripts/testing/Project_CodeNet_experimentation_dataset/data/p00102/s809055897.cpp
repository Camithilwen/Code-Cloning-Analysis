#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	int n,i,j,d,m[11][11];
	while(cin >> n) {
		if (n==0) break;
		memset(m,0,sizeof(m));
		for (i=0;i<n;i++) for (j=0;j<n;j++) {
			cin >> d;
			m[i][j]=d; m[i][n]+=d; m[n][j]+=d; m[n][n]+=d;
		}
		for (i=0;i<=n;i++) {
			for (j=0;j<=n;j++) printf("%5d",m[i][j]);
			printf("\n");
		}
	}
	return 0;
	}