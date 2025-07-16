#include <cstdio>

const char pat3[3][4]={"a..",
		       "a..",
		       ".aa"};
const char pat4[4][5]={"aacd",
		       "bbcd",
		       "cdaa",
		       "cdbb"};
const char pat5[5][6]={"..def",
		       "..def",
		       "aaggh",
		       "bbj.h",
		       "ccjii"};
const char pat6[6][7]={"aacd..",
		       "bbcd..",
		       "..aacd",
		       "..bbcd",
		       "cd..aa",
		       "cd..bb"};
const char pat7[7][8]={"abc....",
		       "abc....",
		       "def....",
		       "def....",
		       "m..gghh",
		       "m..iijj",
		       ".nnkkll"};
		       
char grid[1005][1005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      grid[i][j]='.';
    }
  }
  if(N==2){
    printf("-1\n");
  }else if(N==3){
    for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf("%c",pat3[i][j]);
    }
    printf("\n");
    }
  }else{
    int index=0;
    while(N-index>7){
      for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	  grid[index+i][index+j]=pat4[i][j];
	}
      }
      index+=4;
    }
    if(N-index==4){
      for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	  grid[index+i][index+j]=pat4[i][j];
	}
      }
    }else if(N-index==5){
      for(int i=0;i<5;i++){
	for(int j=0;j<5;j++){
	  grid[index+i][index+j]=pat5[i][j];
	}
      }
    }else if(N-index==6){
      for(int i=0;i<6;i++){
	for(int j=0;j<6;j++){
	  grid[index+i][index+j]=pat6[i][j];
	}
      }
    }else if(N-index==7){
      for(int i=0;i<7;i++){
	for(int j=0;j<7;j++){
	  grid[index+i][index+j]=pat7[i][j];
	}
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	putchar(grid[i][j]);
      }
      printf("\n");
    }
  }
}
