#include <bits/stdc++.h>
using namespace std;
int num(int N){
int a = 0 , b = 1, c;
for(int i = 0 ; i < 9 ; i++){
a += N / b % 10;
b *= 10;
}
c = N % a;
return c;
}
int main(){
  int N;
  cin >> N;
      if(num(N) == 0){
        cout << "Yes" <<endl;
      }
      else if(num(N) != 0){
        cout << "No" << endl;
      }
}