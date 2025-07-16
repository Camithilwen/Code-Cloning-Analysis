#include <iostream>
using namespace std;

int main(){
  int X;
  cin >> X;
  int D = X%10;
  X /= 10;
  int C = X%10;
  X /= 10;
  int B = X%10;
  X /= 10;
  int A = X;
  if(A+B+C+D==7){
    cout <<A<<"+"<<B<<"+"<<C<<"+"<<D<<"=7";
  }else if(A+B+C-D==7){
    cout <<A<<"+"<<B<<"+"<<C<<"-"<<D<<"=7";
  }else if(A+B-C+D==7){
    cout <<A<<"+"<<B<<"-"<<C<<"+"<<D<<"=7";
  }else if(A+B-C-D==7){
    cout <<A<<"+"<<B<<"-"<<C<<"-"<<D<<"=7";
  }else if(A-B+C+D==7){
    cout <<A<<"-"<<B<<"+"<<C<<"+"<<D<<"=7";
  }else if(A-B+C-D==7){
    cout <<A<<"-"<<B<<"+"<<C<<"-"<<D<<"=7";
  }else if(A-B-C+D==7){
    cout <<A<<"-"<<B<<"-"<<C<<"+"<<D<<"=7";
  }else if(A-B-C-D==7){
    cout <<A<<"-"<<B<<"-"<<C<<"-"<<D<<"=7";
  }
  return 0;
}