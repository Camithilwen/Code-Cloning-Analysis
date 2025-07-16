#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#define N 131072 //100000
#define MAXVAL 2147483647 //((long int) ((unsigned long) (1 << 31) - 1))  //*2
int min(int a, int b){return a>b?b:a;}
int max(int a, int b){return a>b?a:b;}
int data[2*131072+100];      //the size of array, for present the tree

//range update and single query

/*
always binary [node_left,node_right]
from top to bottom
*/ 
void update(int update_left, int update_right, int x, int current_node,int node_left,int node_right){
	//not in the range
	if(update_right<node_left||update_left>node_right){
		return;	
	}else if(update_left<=node_left&&update_right>=node_right){
		data[current_node] = x;
	}else{
		//how to check if the
		//unfold the node, the amxValue->-1
		if(data[current_node]!=-1){ //-1: unfold
			//update(node_left, node_right,data[current_node],current_node*2+1,node_left,(node_left+node_right)/2);
			//update(node_left, node_right,data[current_node],current_node*2+2,(node_left+node_right)/2+1, node_right);
			data[2*current_node+1] = data[current_node];
            data[2*current_node+2] = data[current_node];
			data[current_node]=-1;
		}
		//update 
		update(update_left, update_right, x, current_node*2+1,node_left,(node_left+node_right)/2);
		update(update_left, update_right, x, current_node*2+2,(node_left+node_right)/2+1, node_right);
	}
}
//segment of thr last layer
//I did notdeal with 0
//backtrack the tree from the bottom, 
//just update one time
void update2(int x, int node_id,int node_left, int node_right){//x begin from data[0], node_id from 1
	if(x!=-1){
		data[node_id] = x; 
	}
	//printf("%d %d %d\n",node_left,node_right,node_id);
	if(node_left==node_right) {
		return;
	}
	if(data[node_id]!=-1){
		//printf("%d\n",data[node_id]);
		update2(data[node_id], node_id*2+1,node_left, (node_left+node_right)/2);
		update2(data[node_id], node_id*2+2,(node_left+node_right)/2+1, node_right);
		data[node_id]=-1;
	} 
	else {
		update2(-1, node_id*2+1,node_left, (node_left+node_right)/2);
		update2(-1, node_id*2+2,(node_left+node_right)/2+1, node_right);
	}
	
}
//search from top to bottom
int search(int search_left,int search_right, int current_node, int node_left, int node_right){
	if(search_right < node_left || search_left > node_right){
        return -1;//not in the range
	}
	else if(search_left >= node_left && search_right <= node_right&&data[current_node]>=0){//??
		return data[current_node];//for the folded node which parent present the minimal of their children 
	}else {
		int left = search(search_left, search_right,current_node*2+1, node_left,(node_left+node_right)/2);
		int right = search(search_left, search_right,current_node*2+2, (node_left+node_right)/2+1, node_right);
		return max(left,right);
	}
	
}
int main(){
	int n, q;
	FILE *fp = fopen("in.txt","r");
	scanf("%d %d",&n,&q);
	int N = 1;
	while(N<n) N = N<<1;
	if(n==1) N=2;
	for(int i = 0; i<=2*N-2; i++){
		data[i] = MAXVAL;
	}
	//printf("%d",(-1/2));
	for(int i = 0; i<q; i++){
		int temp = 0;
		scanf("%d", &temp);
		int a,b,c;
		
		if(temp == 0) {  //update
			scanf("%d %d %d",&a,&b,&c);
			update(a,b,c,0,0,N-1);
			
		} else if(temp == 1){ //search
			scanf("%d",&a);
			printf("%d\n",search(a,a,0,0,N-1));
		}
	}
	
	return 0;
}