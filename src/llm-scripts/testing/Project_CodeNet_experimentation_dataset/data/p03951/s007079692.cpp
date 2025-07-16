#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  int tmpCnt1,tmpCnt2;
  int Max1 = 0, Max2 = 0;
  string str1, str2;
  cin >> num >> str1 >> str2;
  
  if(str1 == str2){
    cout << num;
    return 0;
  }
  
  for(int i = 0; i < num; i++){
    tmpCnt1 = 0;
    
    if(str1.at(i) == str2.at(0)){
      for(int j = 0; j < num - i; j++){
        if(str1.at(i+j) == str2.at(j)) tmpCnt1++;
        else break;
      }
      Max1 = max(Max1, tmpCnt1);
    }
  }

  for(int i = 0; i < num; i++){
    tmpCnt2 = 0;
    
    if(str2.at(i) == str1.at(0)){
      for(int j = 0; j < num - i; j++){
        if(str2.at(i+j) == str1.at(j)) tmpCnt2++;
        else break;
      }
      Max2 = max(Max2, tmpCnt2);
    }
  }

  if(Max1 == 0 && Max2 == 0){
    cout << num * 2;
  }else if(Max1 >= Max2){
    cout << num + (num - Max1);
  }else{
    cout << num + (num - Max2);
  }
}
