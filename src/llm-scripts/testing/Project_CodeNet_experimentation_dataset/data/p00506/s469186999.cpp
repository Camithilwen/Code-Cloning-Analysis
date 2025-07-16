#include <cstdio>

int n,a[3];

int gdb(int a,int b){
	if(b == 0){
		return a;
	}
	return gdb(b,a%b);
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	int g;
	if(n == 2){
		g = gdb(a[0],a[1]);		
	}
	else{
		g = gdb(gdb(a[0],a[1]),a[2]);
	}
	for(int i = 1; i <= g/2; i++){
		if(g % i == 0){
			printf("%d\n",i);
		}
	}
	printf("%d\n",g);

	return 0;
}

