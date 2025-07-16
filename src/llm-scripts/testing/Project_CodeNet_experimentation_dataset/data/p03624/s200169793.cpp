#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
  string S;
  cin >> S;
  set<char> characters;
  for(int i=0; i<S.size(); i++){
    characters.insert(S.at(i));
  }
  char ans,check='a';
  bool flag = true;
  for(auto itr=characters.begin(); 
      itr!=characters.end(); itr++){
    if(*itr!=check){
      ans=check;
      break;
    }
    if(check=='z'){
      flag = false;
      break;
    }
    check++;
  }
  if(flag){
    cout << ans;
  }else{
    cout << "None";
  }
  return 0;
}