#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin>>a>>b;
  if (a == 1 && b == 1) {
    cout<<"1 2"<<endl;
    cout<<"#."<<endl;
    return 0;
  }
  if (a == 1 || b == 1) {
    cout<<"50 100"<<endl;
  } else {
    cout<<"100 100"<<endl;
  }
  if (a > 1) {
    --b;
    for (int i=0; i<50; i++) {
      for (int j=0; j<100; j++) {
        if (i % 2 == 0 && j % 2 == 0) {
          if (a > 1 || (a == 1 && b == 0)) {
            cout<<'.';
            --a;
          } else {
            cout<<'#';
          }
        } else {
          cout<<'#';
        }
      }
      cout<<endl;
    }
  }
  if (b > 0) {
    for (int i=0; i<50; i++) {
      for (int j=0; j<100; j++) {
        if (i % 2 == 1 && j % 2 == 0) {
          if (b > 0) {
            cout<<'#';
            --b;
          } else {
            cout<<'.';
          }
        } else {
          cout<<'.';
        }
      }
      cout<<endl;
    }
  }
}