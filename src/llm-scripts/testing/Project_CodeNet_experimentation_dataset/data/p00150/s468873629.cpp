#include <iostream>
#include <math.h>
using namespace std;

int fl[10001] = {0};

void isfl(int);
void twlf(int);

int main(void) {
  int tag;

  while(1){
    cin >> tag;
    if(tag == 0) break;
    isfl(tag);
    twlf(tag);
  }
  return 0;
}

void isfl(int tag){
  int i,lim,idx = 2;
  fl[0] = 1;
  fl[1] = 1;

  lim = sqrt(tag);

  while(idx <= lim){
    if(fl[idx] == 0) for(i = idx*2;i<=tag;i+=idx) fl[i] = 1;
    idx++;
  }
  return;
}

void twlf(int tag){
  int k=0,data[10000];
  for(int i=1;i<=tag;i++) if(fl[i] == 0){
    data[k] = i;
    k++;
  }
  for(int i=k-1;i>=0;i--){
    if(data[i] - data[i-1] == 2){
      cout << data[i-1] << " " << data[i] << endl;
      break;
    }
  }
  return;
}