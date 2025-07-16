#include <stdio.h>
#include<math.h>
#include <algorithm>
using namespace std;

int main(){
	int n,a,b,c;

	while(true){
		scanf("%d",&n);
		if(n == 0)break;

		for(int i = 0; i < n; i++){
			scanf("%d %d %d",&a,&b,&c);
			if(a == 100 || b == 100 || c == 100 || a + b >= 180 || a+b+c >= 240){
				printf("A\n");
			}else if((a + b + c >= 210) || (a+b+c>=150 && (a >= 80 || b >= 80))){
				printf("B\n");
			}else{
				printf("C\n");
			}
		}

	}
    return 0;
}