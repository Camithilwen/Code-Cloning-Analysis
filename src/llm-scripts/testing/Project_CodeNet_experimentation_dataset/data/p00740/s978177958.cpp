#include<bits/stdc++.h>
using namespace std;

int N,P;
int D[55];


bool check(int ind){
  for(int i=0;i<N;i++){
    if( i == ind ) continue;
    if( D[i] ) return false;
  }
  return true;
}

int main(){
  while( cin >> N >> P && (N||P) ) {
    memset(D,0,sizeof(D));
    int ind = 0;
    while( 1 ){
      if( P ){
	P--;
	D[ind]++;
	if( P == 0 ){
	  if( check(ind) ) break;
	}
      } else {
	P += D[ind];
	D[ind]=0;
      }
      ind++;
      ind%=N;
    }
    cout << ind << endl;
  }
}