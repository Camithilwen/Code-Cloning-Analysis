#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int A, B, M;
  cin >> A >> B >> M;
  int a[A], b[B], c[M];
  for (int i = 0; i < A; i++){
    cin >> a[i];
  }

  for (int i = 0; i < B; i++){
    cin >> b[i];
  }

  for (int i = 0; i < M; i++){
    int x, y;
    cin >> x >> y >> c[i];
    c[i] = a[x-1] + b[y-1] - c[i];
  }

  sort(a, a+A);
  sort(b, b+B);
  sort(c, c+M);

  if (a[0] + b[0] > c[0]){
    printf("%d\n", c[0]);
  }else{
    printf("%d\n", a[0] + b[0]);
  }
  
  
  
}
