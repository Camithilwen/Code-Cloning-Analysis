#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  string S;
  cin >> S;
  //S の先頭から 3 文字目と末尾から 2 文字目の間（両端含む）に大文字の C がちょうど 1 個含まれる。
  int count = 0;
  int index;
  
  for (int i = 2; i < S.size() - 1; i++) {
    if(S[i] == 'C'){
      count++;
      index = i;
    }
  }
  
  int up_count = 0;
    
  for (int i = 1; i < S.size(); i++) {
    if(i != index){
      if(S[i] >= 'A' && S[i] <= 'Z'){
		up_count++;
      }
    }
  }
  
  
  if(S[0] == 'A' && count == 1 && up_count == 0){
   cout << "AC" << endl;
  }else{
   cout << "WA" << endl;
  }
 
}