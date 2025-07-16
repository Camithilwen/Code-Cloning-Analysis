#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int64_t Y;
  cin >> Y;

  int a = -1;
  int b = -1;
  int c = -1;

  for(int i = 0; i <= N; i++){
    for(int j = 0; j + i <= N; j++){
      int k = (N - i -j);
      int sum = 10000 * i + 5000 * j + 1000 * k;
      if(sum == Y){
        a = i;
        b = j;
        c = k;
      }
    }
  }
 cout << a << " " << b << " " << c << endl;
  
}