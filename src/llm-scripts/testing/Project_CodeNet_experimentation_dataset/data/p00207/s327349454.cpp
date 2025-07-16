#include<iostream>
using namespace std;

int a[102][102],color;

void dfs(int x,int y){
   
    a[y][x] = 9;
    
    if(a[y+1][x] == color){
      dfs(x,y+1);
    }
    if(a[y][x+1] == color){
      dfs(x+1,y);
    }
    if(a[y-1][x] == color){
      dfs(x,y-1);
    } 
    if(a[y][x-1] == color){
      dfs(x-1,y);
    }
 
} 

int main(){

  int xs,ys,xg,yg,n,c,d,x,y,w,h;

  while(1){
  
    cin >>w>>h;
    
    if(w == 0 && h == 0)break;

    for(int i = 0 ; i < 102 ; i++){
      for(int j = 0 ; j < 102 ; j++){
	a[i][j]=0;
      }
    }

    cin >>xs>>ys;
    cin >>xg>>yg;

    cin >>n;

    for(int i = 0 ; i < n ; i++){
      
      cin >> c >> d >> x >> y;
      
      if( d == 0 ){
	for(int i = 0 ; i < 2 ; i++){
	  for(int j = 0 ; j < 4 ; j++){
	    a[i+y][j+x] = c;
	  }
	}
      }else{
	for(int i = 0 ; i < 4 ; i++){
	  for(int j = 0 ; j < 2 ; j++){
	    a[i+y][j+x] = c;
	  }
	}
      }
    
    }
    
    /*
      for(int i = 0 ; i < h+2 ; i ++){
      for(int j = 0 ; j < w+2 ; j++){
      cout << a[i][j];
      }
      cout <<endl;
      }
      cout <<endl;
    */
  
    if(a[ys][xs] != 0){
      color = a[ys][xs];
      dfs(xs,ys);
    }
    
    /*
      for(int i = 0 ; i < h+2 ; i ++){
      for(int j = 0 ; j < w+2 ; j++){
      cout << a[i][j];
      }
      cout <<endl;
      }
    */
    
    if(a[yg][xg] == 9){
      cout <<"OK"<<endl;
    }else{
      cout <<"NG"<<endl;
    }
    
  }      
  
  return 0;
  
}