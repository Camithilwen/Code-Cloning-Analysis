#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  for(int i=0;i<A+B+1;i++){
    char a;
    cin >> a;
    if((i==A&&a!='-')||(i!=A&&a=='-')){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}