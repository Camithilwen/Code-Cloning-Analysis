#include <iostream>
#include <cstdio>
using namespace std;

int S[1000000], cnt = 0;

int sor(int n, int g){
	do{
		
		g = (g - 1) / 3;
		for(int i = g;i < n;i++){
			int j = i - g, v = S[i];
			while(j >= 0 && v < S[j]){
				//printf("*%d*", j);
				S[j + g] = S[j];
				j -= g, cnt++;
			}
			S[j + g] = v;
		}
	}while(g != 1);
	return 0;
}

int main(){
	int g = 1, n, num = 0;
	scanf("%d", &n);
	for(int i= 0;i < n;i++)scanf("%d", &S[i]);
	while(g <= n)g = g * 3 + 1, num++;
	printf("%d\n", num);
	for(int i= g;i != 1;){
		if(i != g)printf(" ");
		i = (i - 1) / 3;
		printf("%d", i);
	}
	puts("");
	sor(n, g);
	printf("%d\n", cnt);
	for(int i= 0;i < n;i++)printf("%d\n", S[i]);
	
	return 0;
}