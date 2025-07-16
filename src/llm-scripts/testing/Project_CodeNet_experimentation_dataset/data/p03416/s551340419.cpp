#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  
  int answer = 0;
  for (int i=A; i<=B; i++){
    int a, b, c, d, e;
    
    a = i % 10;                           //1の位
    b = (i % 100 - i % 10) / 10;          //10の位
    c = (i % 1000 - i % 100) / 100;       //100の位
    d = (i % 10000 - i % 1000) / 1000;    //1,000の位
    e = (i % 100000 - i % 10000) / 10000; //10,000の位
     
    if (a == e && b == d)
      answer++;
  }
  
  cout << answer << endl;
}
