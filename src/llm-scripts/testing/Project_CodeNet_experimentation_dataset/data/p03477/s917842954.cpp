#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d ;
  int L=a+b,R=c+d;
  if (L==R){
    cout << "Balanced" << endl;
  }else 
    cout << (L<R ? "Right" :"Left") << endl;
}
