#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;

#define NUM 2147483647

int N = 1;
int* data;

void init(int first_N){
	while(N < first_N)N *= 2;
}

void update(int update_left,int update_right,int new_value,int node_id,int node_left,int node_right){
	if(update_right < node_left || update_left > node_right)return;
	else if(update_left <= node_left && update_right >= node_right){
		data[node_id] = new_value;
	}else{
		if(data[node_id] >= 0){
			data[2*node_id+1] = data[node_id];
			data[2*node_id+2] = data[node_id];
			data[node_id] = -1;
		}
		update(update_left,update_right,new_value,2*node_id+1,node_left,(node_left+node_right)/2);
		update(update_left,update_right,new_value,2*node_id+2,(node_left+node_right)/2+1,node_right);
	}
}

int query(int search_left,int search_right,int node_id,int node_left,int node_right){
	if(search_right < node_left || search_left > node_right){
		return -1;
	}else if(node_left <= search_left && node_right >= search_right && data[node_id] >= 0){
		return data[node_id];
	}else{
		int left = query(search_left,search_right,2*node_id+1,node_left,(node_left+node_right)/2);
		int right = query(search_left,search_right,2*node_id+2,(node_left+node_right)/2+1,node_right);
		return max(left,right);
	}
}

int main(){
	int first_N,Q;
	scanf("%d %d",&first_N,&Q);

	init(first_N);

	data = new int[270000];

	for(int i = 0; i <= 2*N-2; i++)data[i] = NUM;

	int command,left,right,value,loc;

	for(int i = 0; i < Q; i++){
		scanf("%d",&command);

		if(command == 0){
			scanf("%d %d %d",&left,&right,&value);
			update(left,right,value,0,0,N-1);
		}else{
			scanf("%d",&loc);
			printf("%d\n",query(loc,loc,0,0,N-1));
		}
	}
}