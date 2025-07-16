#include <cstdio>
#include <iostream>
using namespace std;

int a[11][11];

int main()
{
  int i, j;
  int n;
  
  while (1){
    cin >> n;
    if (n == 0){
      break;
    }
    for (i = 0; i <= n; i++){
      for (j = 0; j <= n; j++){
        a[i][j] = 0;
      }
    }

    for (i = 0; i < n; i++){
      for (j = 0; j < n; j++){
        cin >> a[i][j];
      }
    }

    for (i = 0; i < n; i++){
      for (j = 0; j <= n; j++){
        a[i][n] += a[i][j];
      }
    }
    for (j = 0; j <= n; j++){
      for (i = 0; i <= n; i++){
        a[n][j] += a[i][j];
      }
    }
    for (i = 0; i <= n; i++){
      a[i][n] /= 2;
    }
    for (j = 0; j <= n; j++){
      a[n][j] /= 2;
    }

    for (i = 0; i <= n; i++){
      printf("%5d", a[i][0]);
      for (j = 1; j <= n; j++){
        printf("%5d", a[i][j]);
      }
      cout << endl;
    }
  }
  return 0;
}