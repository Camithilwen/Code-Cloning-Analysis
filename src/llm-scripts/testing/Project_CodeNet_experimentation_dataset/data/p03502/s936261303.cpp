#include <bits/stdc++.h>
using namespace std;


int func(int N){// 例: 11221213312, 12,  432,  8
  if (N < 10) return N;
  return func(N/10) + N % 10;
}

int main()
{
  int n; 
  cin >> n;
  int s = func(n);
  if (n % s == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;

}