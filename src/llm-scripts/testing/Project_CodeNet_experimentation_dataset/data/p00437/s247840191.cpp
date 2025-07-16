#include <iostream>
 
using namespace std;
 
int main() {
 
  int a,b,c;
 
  while(1) {
  cin >> a >> b >> c;
  if(a == 0 && b == 0 && c == 0) break;
 
  int n;
  cin >> n;
 
  int flg[301];
 
  for(int i=0;i<301;i++) flg[i] = 2;
 
  int d[1001],m[1001],k[1001],r;
 
  for(int i=0;i<n;i++) {
    cin >> d[i]>> m[i] >> k[i] >> r;
    if(r == 1) {
      flg[d[i]] = flg[m[i]] = flg[k[i]] = 1;
      i--;
      n--;
    }
  }
  int sum;
  for(int i=0;i<n;i++){
    sum = 0;
    if(flg[d[i]] == 1 ) sum++;
    if(flg[m[i]] == 1)  sum++;
    if(sum == 2) {
      flg[k[i]] = 0;
      continue;
    }
    if(flg[k[i]] == 1) sum++;
    if(sum == 2) {
      if(flg[d[i]] == 2) flg[d[i]] = 0;
      else flg[m[i]] = 0;
    }
  }
   
   
  for(int i=1;i<=a+b+c;i++) {
    cout << flg[i] << endl;
  }
   
   
   
  }
 
  return 0;
}