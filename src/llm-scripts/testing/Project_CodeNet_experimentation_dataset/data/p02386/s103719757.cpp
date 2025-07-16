#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class Dice{

private:

public:

  int num[6];

  void roll(char c){
    int b;
    if(c == 'S'){
      b = num[0];
      num[0] = num[4];
      num[4] = num[5];
      num[5] = num[1];
      num[1] = b;
    }
    if(c == 'W'){
      b = num[0];
      num[0] = num[2];
      num[2] = num[5];
      num[5] = num[3];
      num[3] = b;
    }
    if(c == 'N'){
      b = num[0];
      num[0] = num[1];
      num[1] = num[5];
      num[5] = num[4];
      num[4] = b;
    }
    if(c == 'E'){
      b = num[0];
      num[0] = num[3];
      num[3] = num[5];
      num[5] = num[2];
      num[2] = b;
    }
  }
};

bool isSame(Dice d1, Dice d2){
  int top = d1.num[0], front = d1.num[1];
  if(d2.num[2] == front || d2.num[3] == front) d2.roll('W');
  int cnt = 0;
  while(d2.num[1] != front){
    d2.roll('S');
    if(++cnt == 4) return false;
  }
  cnt = 0;
  while(d2.num[0] != top){
    d2.roll('W');
    if(++cnt == 4) return false;
  }
  for(int i=2;i<6;i++){
    if(d1.num[i] != d2.num[i]){
      return false;
    }
  }
  return true;
}

bool isAllDiff(vector <Dice> d, int n){
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(isSame(d[i], d[j])){
	return false;
      }
    }
  }
  return true;
}

int main(){
  vector <Dice> vec;
  Dice d;
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<6;j++){
      cin >> d.num[j];
    }
    vec.push_back(d);
  }

  if(isAllDiff(vec, n)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

