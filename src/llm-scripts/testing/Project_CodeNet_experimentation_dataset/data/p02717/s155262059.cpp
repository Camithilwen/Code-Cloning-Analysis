#include<iostream>

using namespace std;

void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(void){
  int a,b,c;
  cin >> a >> b >> c;
  swap(&a,&b);
  swap(&a,&c);
  cout << a <<" "<< b << " " << c << endl;
  return 0;
}
