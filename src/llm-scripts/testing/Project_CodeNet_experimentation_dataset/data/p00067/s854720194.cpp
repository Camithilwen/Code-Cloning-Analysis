#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

bool rangeCheck(int row,int col){
	if(row >= 0 && row <= 11 && col >=0 && col<= 11)return true;
	else{
		return false;
	}
}

void erase(char buf[12][13],int row,int col){
	buf[row][col] = '0';
	if(rangeCheck(row,col-1)&&buf[row][col-1] == '1')erase(buf,row,col-1);
	if(rangeCheck(row+1,col)&&buf[row+1][col] == '1')erase(buf,row+1,col);
	if(rangeCheck(row,col+1)&&buf[row][col+1] == '1')erase(buf,row,col+1);
}

int main(){

	char buf[12][13];
	int count;

	while(scanf("%s",buf[0])!=EOF){
		for(int i=1; i <= 11; i++){
			scanf("%s",buf[i]);
		}
		getchar();
		count = 0;

		for(int i=0; i < 12; i++){
			for(int k=0; k < 12; k++){
				if(buf[i][k] == '1'){
					count++;
					erase(buf,i,k);
				}
			}
		}

		printf("%d\n",count);
	}
	return 0;
}