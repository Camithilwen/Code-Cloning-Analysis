#include<iostream>

using namespace std;

const int coin[2] = {5,500};

int main(){
  int money,happy;
  cin >> money;
  int C[2] = {0,0};
  for(int i = 1;i >= 0;i--){
    C[i] = money / coin[i];
    money -= coin[i]*C[i];
  }
  happy = C[0]*5 + C[1]*1000;
  cout << happy << endl;
  return 0;
}