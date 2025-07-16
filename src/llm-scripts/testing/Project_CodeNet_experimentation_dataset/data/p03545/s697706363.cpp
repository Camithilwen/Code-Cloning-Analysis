#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<int> v(4);
  for(int i = 0; i < 4; i++){
    v.at(i) = (int)S.at(i) - (int)'0';
  }
  
  bool finish = false;
  
  for (int tmp = 0; tmp < (1 << 3); tmp++){
    if(finish) break;
    bitset<3> s(tmp);
    int test = v.at(0);
    int sign = 1;
    string op = "+++";
    for(int i = 0; i < 3; i++){
      if(s.test(i)){
        sign = -1;
        op.at(i)='-';
      }else{
        sign = 1;
      }
      test += sign * v.at(i+1);
    }
    if(test == 7){
      for(int i=0; i<3;i++){
        cout << v.at(i) << op.at(i);
      }
      cout << v.at(3) << "=7" << endl;
      finish = true;
    }
  }
  
}
