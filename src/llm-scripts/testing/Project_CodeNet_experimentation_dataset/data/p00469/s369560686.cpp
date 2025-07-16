#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int a[10];
int v[10000] = {};
int s;

void set_vec(int t, int f, int sum) {
	if(t>=k) {
		v[s] = sum;
		s++;
	}else {
		for(int i=0;i<n;i++) {
			if((1<<i) & f)continue;
			set_vec(t+1, f+(1<<i), sum*(a[i]<10?10:100)+a[i]);
		}
	}
}

int main() {
	
	while(1) {
		scanf("%d", &n);
		scanf("%d", &k);
		if(n==0 && k==0)break;
		s = 0;
		for(int i=0;i<n;i++) {
			scanf("%d", &a[i]);
		}
		
		set_vec(0, 0, 0);
		
		sort(v, v+s);
		
		int t = 0;
		int sum = 0;
		
		for(int i=0;i<s;i++) {
			if(t==v[i])continue;
			sum++;
			t=v[i];
		}
		
		printf("%d\n", sum);
		
	}
	
	return  0;
}