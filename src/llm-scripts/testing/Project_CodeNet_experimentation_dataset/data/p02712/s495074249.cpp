#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    long long int ans=0;
    for(int i=1;i<=n;i++){
       if(i%3==0 ||i%5==0){
           continue;
       }
       ans +=i;
    }
    printf("%lld\n", ans);
    return 0;
}