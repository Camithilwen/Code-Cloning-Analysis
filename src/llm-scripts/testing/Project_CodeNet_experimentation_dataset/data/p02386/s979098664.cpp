#include<iostream>
#include<string>
using namespace std;

class Dice{
public:
  int face[6];
  Dice(){}

  void roll_x(){ roll(0,3,5,2);}
  void roll_y(){ roll(0,1,5,4);}
  void roll_z(){ roll(1,2,4,3);}
  void roll(int i, int j, int k, int l){
    int t = face[i]; face[i] = face[j]; face[j] = face[k]; face[k] = face[l]; face[l] = t;
  }
};

bool check(Dice d1,Dice d2){
  for (int i = 0; i < 6; i++){
    if (d1.face[i] != d2.face[i]) return false;
  }
  return true;
}

bool equal(Dice d1, Dice d2){
  for(int j = 0; j < 6; j++){
    for(int k = 0; k < 4; k++){
      if(check(d1, d2)) return true;
      d1.roll_z();
    }

    if(check(d1,d2)) return true;
    if (j == 2) d1.roll_y();
    else d1.roll_x();
  }
  return false;
}

bool equal_all(Dice d[],int n){
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
      if(equal(d[i],d[j])) return true;
    }
  }
  return false;
}

int main(){
  int n;
  cin >> n;
  // ???????????????????????????
  Dice d[100];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 6; j++){
    cin >> d[i].face[j];
    }
  }

  //??????
  if(equal_all(d,n)) cout << "No" << endl;
  else cout << "Yes" << endl;

  return 0;
}