#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct Info{
	char name[21];
	double seed_price,before_leaf,after_leaf,num,sell_price,count,rate;
};

//???????????????????????????3,left?????????????????´??????1,right?????????????????¨??????2
int strCmp2(char* left,char* right){
	int i;

	for(i=0;left[i] != '\0' && right[i] != '\0'; i++){
		if(left[i] != right[i]){
			if(left[i] < right[i])return 1;
			else{
				return 2;
			}
		}
	}
	if(left[i] == '\0')return 1;
	else{
		return 2;
	}
}

void func(int N){
	Info info[N];
	double A,B,C,D,E,sum,total_time;

	for(int loop = 0; loop < N; loop++){
		scanf("%s %lf %lf %lf %lf %lf %lf %lf %lf %lf",info[loop].name,&info[loop].seed_price,&A,&B,&C,&D,&E,&info[loop].num,&info[loop].sell_price,&info[loop].count);
		info[loop].before_leaf = A+B+C;
		info[loop].after_leaf = D+E;

		sum = 0;
		total_time = info[loop].before_leaf;
		for(int i = 0; i < info[loop].count; i++){
			total_time += info[loop].after_leaf;
			sum += info[loop].sell_price*info[loop].num;
		}
		sum -= info[loop].seed_price;
		info[loop].rate = sum/total_time;
	}

	for(int i = 1; i <= N-1; i++){
		for(int k = N-1; k >= i; k--){
			if(info[k].rate > info[k-1].rate)swap(info[k],info[k-1]);
			else if(info[k].rate == info[k-1].rate && strCmp2(info[k].name,info[k-1].name) == 1)swap(info[k],info[k-1]);
		}
	}

	for(int i = 0; i < N; i++)printf("%s\n",info[i].name);
	printf("#\n");

}

int main(){
	int N;

	while(true){
		scanf("%d",&N);
		if(N == 0)break;

		func(N);
	}

}