#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	char c[101],m[7]={'I','V','X','L','C','D','M'};
	int s,i,j,h,n[7]={1,5,10,50,100,500,1000};
  while(gets(c)!=NULL) {
    s=0; h=10;
	for (i=0;i<strlen(c);i++) {
     for (j=0;j<7;j++) if (c[i]==m[j]) break;
	 s+=n[j];
	 if (h<j) s-=n[h]*2;
	 h=j;
	}
    cout << s << endl;
  }
  return 0;
}