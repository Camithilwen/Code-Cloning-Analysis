#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string str;
  cin >> str;
  
  int num = 0;
  
  for(int i = 0; i < (int)str.size(); ++i){
    num +=(int)(str[i] - '0');
  }
  
      int N = atoi(str.c_str());
  
  if(N % num == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  
}