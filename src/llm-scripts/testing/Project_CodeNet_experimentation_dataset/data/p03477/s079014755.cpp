#include <bits/stdc++.h>
using namespace std;

int main() {
int a,b,c,d;
  cin >> a >> b >> c >> d;
  int L=a+b;
  int R=c+d;
  if(L>R){
    cout << "Left" << endl;
  }
    if(L<R){
      cout << "Right" << endl;
    }
  if(L==R){
    cout << "Balanced" << endl;
  }
}
