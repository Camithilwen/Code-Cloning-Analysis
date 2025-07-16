#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,h,w;
  cin >> n >> h >> w;
  int a = 0;
  int b = 0;
  for(int i = 1; i <= n; i++){
    if(i+w-1 <= n) a++;
    if(i+h-1 <= n) b++;
  }
  cout << a*b << endl;
  return 0;
}