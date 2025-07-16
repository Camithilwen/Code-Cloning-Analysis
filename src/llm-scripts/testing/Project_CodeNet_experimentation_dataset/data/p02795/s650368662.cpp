#include <stdio.h>

int main(){
    int h,w,n;
    scanf("%d", &h);
	scanf("%d", &w);
	scanf("%d", &n);
  
    int ans = 0, count = 0;
   
    while (n > ans){
        if(w >= h){
            ans += w;
            count++;
        }else if(h>w){
            ans += h;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
