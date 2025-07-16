#include <iostream>
using namespace std;

int main(){
  double a[10], v1, v2;
  double t1[11], t2[11];
  int cross;
  char k;
  int i;

  while(cin>>a[0]){
    for(i=1; i<10; i++) cin>>k>>a[i];
    cin>>k>>v1>>k>>v2;
    t1[0]=0;
    for(i=1; i<11; i++) t1[i]=t1[i-1]+a[i-1]/v1;
    t2[10]=0;
    for(i=9; i>=0; i--) t2[i]=t2[i+1]+a[i]/v2;
    for(i=1; i<11; i++){
      if(t1[i]>=t2[i]){
        cross=i; break;
      }
    }
    printf("%d\n", cross);
  }

  return 0;
}