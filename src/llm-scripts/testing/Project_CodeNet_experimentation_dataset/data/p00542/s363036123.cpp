#include <stdio.h>
#include<math.h>
#include <algorithm>
using namespace std;

int main(){
	int subA[4],subB[2];

	for(int i=0; i < 4; i++)scanf("%d",&subA[i]);
	for(int i=0; i < 2; i++)scanf("%d",&subB[i]);

	for(int i = 1; i <= 3; i++){
		for(int k = 3; k >= i; k--){
			if(subA[k] > subA[k-1]){
				swap(subA[k],subA[k-1]);
			}
		}
	}
	if(subB[1] > subB[0])swap(subB[1],subB[0]);

	printf("%d\n",subA[0]+subA[1]+subA[2]+subB[0]);

    return 0;
}