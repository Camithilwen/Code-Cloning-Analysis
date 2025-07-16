#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
  int b[10],k[10],i,v1,v2;
  double h;
  while (scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&b[0],&b[1],&b[2],&b[3],&b[4],&b[5],&b[6],&b[7],&b[8],&b[9],&v1,&v2)!=EOF) {
    k[0]=b[0];
	for (i=1;i<10;i++) k[i]=k[i-1]+b[i];
	h=(double)k[9]*v1/(v1+v2);
	for (i=0;i<10;i++) if (h>=k[i]-b[i] && h<=k[i]) break;
	cout << i+1 << endl;
  }
  return 0;
  }