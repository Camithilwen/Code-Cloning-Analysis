#include<iostream>
using namespace std;
int main(){
  int a,b,c,d; cin >> a >> b >> c >> d;
  int e = a+b-c-d;
  if(e>0)cout << "Left" << endl;
  else if(e<0)cout << "Right" << endl;
  else cout << "Balanced" << endl;
}