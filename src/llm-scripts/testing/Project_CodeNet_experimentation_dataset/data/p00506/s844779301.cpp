#include <cstdio>

int main(){
	int n;
	int a[3];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= 100000000; i++){
		bool ok = true;
		for(int j = 0; j < n; j++){
			if(a[j]%i != 0) ok = false;
		}
		if(ok) printf("%d\n", i);
	}
}