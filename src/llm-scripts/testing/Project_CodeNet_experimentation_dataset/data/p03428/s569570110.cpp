#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, x[105], y[105];
double mx, z[105], PI = acos(-1.0);
int main() {
	int i, j, k;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d%d", &x[i], &y[i]);
	for(i=0; i<n; i++) {
		for(j=k=0; j<n; j++) if(i!=j) z[k++] = atan2(y[j]-y[i], x[j]-x[i]);
		sort(z, z+k);
		mx = z[0] - z[k-1] + 2*PI ;
		for(j=1; j<k; j++) mx = max(mx, z[j] - z[j-1]);
		printf("%.9f\n", max(0., (mx-PI)/2./PI));
	}
	return 0;
}