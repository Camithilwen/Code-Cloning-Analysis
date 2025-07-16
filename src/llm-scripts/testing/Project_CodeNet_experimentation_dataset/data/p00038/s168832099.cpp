#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int c[6] = {0},same[5] = {0};

  while(scanf("%d,%d,%d,%d,%d\n",&c[0],&c[1],&c[2],&c[3],&c[4]) == 5) {
    int same[5] = {0};
    int straight = 0;
    for(int i=0;i<5;i++) {
      for(int j=0;j<5;j++) {
	if(c[i] == c[j]) {
	  same[i]++;
	}
      }
    }
    sort(c,c+5);
    sort(same,same+5);
    if(same[4] == 4) {
      cout << "four card" << endl;
    }
    else if(same[4] == 3) {
      if(same[1] == 2) {
	cout << "full house" << endl;
      }
      else {
	cout << "three card" << endl;
      }
    }
    else if(same[4] == 2) {
      if((same[3] == 2) &&(same[2] == 2)) {
	cout << "two pair" << endl;
      }
      else {
	cout << "one pair" << endl;
      }
    }
    else if(same[4] == 1) {
      for(int i=0;i<4;i++) {
	if(c[i] == c[i+1]-1) {
	  straight = 1;
	}
	else {
	  straight = 0;
	  break;
	}
      }
      if((c[0] == 1) && (c[1] == 10)) {
	straight = 1;
      }
      if(straight) {
	cout << "straight" << endl;
      }
      else {
	cout << "null" << endl;
      }
    }

  }
}