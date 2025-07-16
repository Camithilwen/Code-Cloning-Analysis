#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  const int num = S.size();

  string T;

  for (int64_t tmp = 0; tmp < (1 << 3); tmp++) {

    bitset<3> b(tmp);

    int sum = S.at(0)-'0';
    T = "";
    for (int i = 0; i < 3; i++) {

      if(b.test(0)){
        sum += S.at(i+1)-'0';
		T += "+";
      }else{
        sum -= S.at(i+1)-'0';
      	T += "-";
      }
      b = b >> 1;
      
    }

    if(sum == 7)
      break;
  }
  

  
  for (int i = 0; i < 3; i++) {
   cout << S.at(i) << T.at(i); 
  }
  cout << S.at(3) << "=7" << endl; 

  

}
