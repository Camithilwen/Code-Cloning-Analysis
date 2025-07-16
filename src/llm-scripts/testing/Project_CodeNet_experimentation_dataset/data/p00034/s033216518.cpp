#include <bits/stdc++.h>

using namespace std;

int main() {

  int l[10], v[2];
  double total, point, now;

  while(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &l[0], &l[1], &l[2], &l[3], &l[4], &l[5], &l[6], &l[7], &l[8], &l[9], &v[0], &v[1]) + 1) {

    total = 0;
    now = 0;

    for(int i = 0; i < 10; ++i) total += l[i];

    point = total * v[0] / (v[0] + v[1]);
    
    for(int i = 0; i < 10; ++i) {
      now += l[i];
      if(now >= point) {
	cout << i + 1 << endl;
	break;
      }
    }

    //cout << total << " " <<  point << endl;

  }

}