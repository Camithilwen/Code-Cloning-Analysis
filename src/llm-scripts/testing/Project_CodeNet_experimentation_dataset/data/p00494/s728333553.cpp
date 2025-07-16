#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
using namespace std;
char str[1000000];
int main() {
  int ans, k, len, J, O, I;
  int a;
  //string str;
  
  while(scanf("%s", str) != EOF) {
    len = strlen(str);
    J=0, O=0, I=0;
    ans=0, k=0;
    //cout << len << endl;
    for(int i = 0 ; i < len ; i++) {
      if(str[i] != 'J') continue;

      if(str[i] == 'J') {
	if(str[i] != '#') a = i;
	while(str[a] == 'J') {
	  str[a] = '#';
	  a++;
	  J++;
	}
	if(str[a] == 'O') {
	  while(str[a] == 'O') {
	    a++;
	    O++;
	  }
	  if(str[a] == 'I') {
	    while(str[a] == 'I') {
	      a++;
	      I++;
	    }
	  }
	}
      }
      //printf("J = %d, O = %d, I = %d\n", J, O, I);
      if(O <= J && O <= I) k = min(J, min(O, I));
      //if(J == O && O == I /*|| J <= O && O >= I*/) k = min(J, min(O, I));
      //else J = 0; O = 0; I = 0;
      ans = max(k, ans);
      J = 0; O = 0; I = 0;
        
    }
    cout << ans << endl;
  }
  return 0;
}