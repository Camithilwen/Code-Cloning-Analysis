#include <bits/stdc++.h>
using namespace std;
int main(){
 int N;
  cin >> N;
  int n = N;
  int O,Y,A,U,M,S,H,J,I;
  O = N / 100000000;
  N = N % 100000000;
  Y = N / 10000000;
  N = N % 10000000;
  A = N / 1000000;
  N = N % 1000000;
  U = N / 100000;
  N = N % 100000;
  M = N / 10000;
  N = N % 10000;
  S = N / 1000;
  N = N % 1000;
  H = N / 100;
  N = N % 100;
  J = N / 10; 
  N = N % 10;
  I = N;
  int Goukei = O+Y+A+U+M+S+H+J+I;
    if(n % Goukei == 0){
      cout <<"Yes"<< endl; 
    }
  else{
    cout <<"No"<< endl;
  }
}