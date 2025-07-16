#include<stdio.h>

int main(){
	
	
	int h, w, n, ans;
	
	scanf("%d", &h);
	scanf("%d", &w);
	scanf("%d", &n);
	
	if(w>=h){
		if(n%w == 0){
			ans = n/w;
		}else if(n%w != 0){
			ans = n/w+1;
		}
	
	}else if(w<=h){
		if(n%h == 0){
			ans = n/h;
		}else if(n%h != 0){
			ans = n/h+1;
		}
	}
	printf("%d", ans);
}