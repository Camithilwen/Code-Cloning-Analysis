#include<bits/stdc++.h>
using namespace std;

int main(){
  int n = 0;
  cin >> n;
  int count = 200;
  for (int i = 0;i < n;i++) {
    int subcount = 0;
    int a =0;
    cin >> a;
    for (int j = a;j > 1;j /= 2){
      if( (j % 2) == 1) {
        break;
      }
      else {
        subcount++;
      }
    }
    if (count > subcount){
      count = subcount;
    }
  }
  cout << count << endl;
}
