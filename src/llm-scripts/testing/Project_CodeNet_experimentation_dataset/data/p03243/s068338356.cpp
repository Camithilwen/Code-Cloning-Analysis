#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  scanf("%d", &N);
  
  int x = N / 111;
  if(N % 111 !=0) x++;
  
  printf("%d\n",x * 111);
  return 0;
}