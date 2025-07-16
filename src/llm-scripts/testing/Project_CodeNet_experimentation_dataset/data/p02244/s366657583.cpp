#include <stdio.h>

using namespace std;

int final_board[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};

void deletePossibility(int tmp_board[8][8],int row,int column){
	tmp_board[row][column] = 1;
	for(int i = 0; i < 8; i++){
		if(i != column){
			tmp_board[row][i] = -1;
		}
	}
	for(int i = 0; i < 8; i++){
		if(i != row){
			tmp_board[i][column] = -1;
		}
	}

	for(int r = row-1,c = column+1;r >= 0 && c <= 7; r--,c++){
		tmp_board[r][c] = -1;
	}
	for(int r = row+1,c = column+1;r <= 7 && c <= 7; r++,c++){
		tmp_board[r][c] = -1;
	}
	for(int r = row-1,c = column-1;r >= 0 && c >= 0; r--,c--){
		tmp_board[r][c] = -1;
	}
	for(int r = row+1,c = column-1;r <= 7 && c >= 0; r++,c--){
		tmp_board[r][c] = -1;
	}
}



void func(int tmp_board[8][8],int num_of_putQ){
	if(num_of_putQ == 8){
		for(int i = 0; i < 8; i++){
			for(int k = 0; k < 8; k++){
				final_board[i][k] = tmp_board[i][k];
			}
		}
	}else{

		int row,column,count = 0;
		for(row = 0; row < 8; row++){
			for(column = 0; column < 8; column++){
				if(tmp_board[row][column] == 0){
					count++;
				}
			}
			if(count > 0) break;
		}
		if(row == 8 && column == 8){
			//Do nothing
		}else{
			int tri_board[count][8][8];
			int index = 0;

			for(int a = 0; a < count; a++){
				for(int b = 0; b < 8; b++){
					for(int c = 0; c < 8; c++){
						tri_board[a][b][c] = tmp_board[b][c];
					}
				}
			}

			for(int i = 0; i < 8; i++){
				if(tmp_board[row][i] == 0){
					deletePossibility(tri_board[index],row,i);
					func(tri_board[index++],num_of_putQ+1);
				}
			}
		}

	}
}




int main(){

	int k,row,colum;
	int tmp_board[8][8];

	for(int i = 0; i < 8; i++){
		for(int k = 0; k < 8; k++){
			tmp_board[i][k] = 0;
		}
	}

	scanf("%d",&k);

	for(int i = 0; i < k; i++){
		scanf("%d %d",&row,&colum);
		deletePossibility(tmp_board,row,colum);
	}

	func(tmp_board,k);

	for(int i = 0; i < 8; i++){
		for(int p = 0; p < 8; p++){
			if(final_board[i][p] == 1){
				printf("Q");
			}else{
				printf(".");
			}
		}
		printf("\n");
	}

    return 0;
}