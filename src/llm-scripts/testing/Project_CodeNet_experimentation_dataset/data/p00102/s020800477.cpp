#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;



int main(){

	int n,tmp,row_sum,col_sum[11];

	while(true){
		scanf("%d",&n);
		if(n == 0)break;

		for(int i=0; i < 11; i++)col_sum[i] = 0;

		for(int i=0; i < n; i++){
			row_sum = 0;
			for(int k=0; k < n; k++){
				scanf("%d",&tmp);
				printf("%5d",tmp);
				row_sum += tmp;
				col_sum[k] += tmp;
			}
			printf("%5d\n",row_sum);
			col_sum[n] += row_sum;
		}
		for(int i=0; i <= n; i++)printf("%5d",col_sum[i]);
		printf("\n");
	}

    return 0;
}

