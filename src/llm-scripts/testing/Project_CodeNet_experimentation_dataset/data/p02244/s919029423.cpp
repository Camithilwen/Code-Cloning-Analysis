#include<stdio.h>
#include<string.h>
#define N 8
int board[N][N];
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_A -- backtracking
//chech previous part but there are fixed point before that
//so check all of them
bool safe(int row, int col){
	//chec the column
	if(board[row][col]==1) return true;
	for(int i = 0; i<N; i++){
		if(board[row][i] == 1) return false;
	}
	//check the row
	for(int i = 0; i<N; i++){
		if(board[i][col] == 1) return false;
	}
	//check the diagional
	int i = row, j = col;
	while(i>=0 && j>=0){
		if(board[i][j]==1) return false;
		i--; j--;
	}
	i = row, j = col;
	while(i<N && j<N){
		if(board[i][j]==1) return false;
		i++; j++;
	}
	i = row, j = col;
	while(i>=0 && j<N){
		if(board[i][j]==1) return false;
		i--; j++;
	}
	i = row, j = col;
	while(i<N && j>=0){
		if(board[i][j]==1) return false;
		i++; j--;
	}
	//printf("check\n");
	return true;
}

//for each row([0,7]),check the column
bool solve_board(int col){
	//all chess placed
	if(col>=N) return true;
	for(int i = 0; i<N; i++){
		if(board[i][col]==1){
			if(solve_board(col+1)) return true;
		}
		else {
		if(safe(i,col)){
			//printf("%d %d\n",i,col);
			board[i][col] = 1;
			//recur--key points
			if(solve_board(col+1)) return true; 
			board[i][col] = 0;
		}}
		
	}
	return false;
}

int main(){
	int n = 0;
	memset(board,0,sizeof(board));
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		board[a][b] = 1;
	}
	//for each column, check the row
	solve_board(0);
	for(int i = 0; i<N; i++){
		for(int j = 0; j< N; j++){
			if(board[i][j]==0) printf(".");
			else printf("Q");
		}
		printf("\n");
	}
}
