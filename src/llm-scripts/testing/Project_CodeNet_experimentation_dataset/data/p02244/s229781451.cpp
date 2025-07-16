#include <iostream>
#include <cstring>
using namespace std;

#define N 8


bool col[N],hi[2*N-1],mi[2*N+1];
int row[N];
void point(int y,int x){

  row[y] = x;
  col[x] = false;
  hi[x+y] = false;
  mi[y-x+N-1] = false;

}

void del(int y, int x){

  row[y] = -1;
  col[x] = true;
  hi[x+y] = true;
  mi[y-x+N-1] = true;

}

void print_ans(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(row[i] == j) cout << "Q";
      else cout << ".";
    }
    cout << endl;
  }
}

bool is_ok(int y,int x){
  return row[y] == -1 && col[x] == true && hi[x+y] == true && mi[y-x+N-1];
}

void dfs(int r){
  if(r == 8){//??´??????
    print_ans();
    return ;
  }
  if(row[r] != -1){
    dfs(r+1);
  }
  else{
    for(int i=0; i<8; i++){
      if(is_ok(r,i) == true){
	point(r,i);
	dfs(r+1);
	del(r,i);
      }
    }
  }
  return;
}


int main(){

  int k; cin >> k;
  
  memset(row,-1,sizeof(row));
  memset(col,true,sizeof(col));
  memset(hi,true,sizeof(hi));
  memset(mi,true,sizeof(mi));
  
  for(int i=0; i<k; i++){
    int x,y; cin >> y >> x;
    row[y] = x;
    col[x] = false;
    hi[x+y] = false;
    mi[y-x+N-1] = false;
  }
  
  dfs(0);

}