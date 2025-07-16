#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void){
  char buf[128] = { 0 };
  short grid[64][64] = { {0} };
  int H,W;
  
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d %d", &H, &W);
  
  for(int i = 0; i < H; i++){
    memset(buf, 0, sizeof(buf));
    fgets(buf, sizeof(buf), stdin);
    for(int j = 0; j < W; j++)
      if(buf[j] == '#') grid[i+1][j+1] = 1;          
  }
  
  int flag = 0;
  for(int i = 1; i < H+1; i++){
    for(int j = 1; j < W+1; j++){
      if(grid[i][j] == 0) continue;
      else{
        if(grid[i-1][j] != 1 && grid[i][j-1] != 1 
           && grid[i+1][j] != 1 && grid[i][j+1] != 1){
          flag = 1;
          break;
        }
      }
    }
    if(flag) break;
  }
  if(flag == 0) printf("Yes\n");
  else printf("No\n");
  return 0;
}
