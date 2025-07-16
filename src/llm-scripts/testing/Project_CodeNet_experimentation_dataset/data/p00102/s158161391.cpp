#include <cstdio>
#include <iostream>

using namespace std;

int main() {

	int i, j, n, m[11][11];

	while(cin >> n) {
		if(n==0)
			break;
		for(i=0; i<n+1; i++) {
			for(j=0; j<n+1; j++) {
				m[i][j]=0;
			}
		}
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				cin >> m[i][j];
				m[i][n]+=m[i][j];
				m[n][j]+=m[i][j];
				m[n][n]+=m[i][j];
			}
		}
		for(i=0; i<n+1; i++) {
			for(j=0; j<n+1; j++) {
				printf("%5d", m[i][j]);
				if(j==n)
				 cout << endl;
			}
		}

	}

	return 0;

}