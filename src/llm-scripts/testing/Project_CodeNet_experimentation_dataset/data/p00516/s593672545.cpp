#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

struct Info{
	Info(){
		rank = cost = point = 0;
	}
	int cost,point,rank;
};

int main(){

	int num_sport,num_member,cost_limit,maximum,max_index;

	Info info[1000];

	scanf("%d %d",&num_sport,&num_member);

	for(int i = 0; i < num_sport; i++){
		scanf("%d",&info[i].cost);
		info[i].rank = i+1;
	}

	for(int i = 1; i <= num_sport-1; i++){
		for(int k = num_sport-1; k >= i; k--){
			if(info[k].cost < info[k-1].cost)swap(info[k],info[k-1]);
		}
	}

	for(int i = 0; i < num_member; i++){
		scanf("%d",&cost_limit);
		maximum = 1000000000;
		for(int k = 0; k < num_sport; k++){
			if(info[k].cost > cost_limit)break;
			if(info[k].rank < maximum){
				maximum = info[k].rank;
				max_index = k;
			}
		}
		info[max_index].point++;
	}

	maximum = -1;

	for(int i = 0; i < num_sport; i++){
		if(info[i].point > maximum){
			maximum = info[i].point;
			max_index = i;
		}
	}

	printf("%d\n",info[max_index].rank);
	return 0;
}