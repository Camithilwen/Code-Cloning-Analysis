#include<iostream>
using namespace std;

int a[10];
int b[10];

int score(int x[10]){
  int a=0,b=0,c=0,tmp;

  for(int i=0;i<10;i++){
    if(a < x[i]){
      tmp = a;
      a = x[i];
      x[i] = tmp;
    }
    if(b < x[i]){
      tmp = b;
      b = x[i];
      x[i] = tmp;
    }
    if(c < x[i]){
      tmp = c;
      c = x[i];
      x[i] = tmp;
    }
  }
  return a + b + c;
}
int main(){
  for(int i=0;i<10;i++)cin >> a[i];
  for(int i=0;i<10;i++)cin >> b[i];

  int sa = score(a);
  int sb = score(b);
  
  cout << sa << " " << sb << endl;

  return 0;
}