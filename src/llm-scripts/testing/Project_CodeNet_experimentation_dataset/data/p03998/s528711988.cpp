#include <iostream>
#include <map>
#include <cctype>
using namespace std;

char getResult(map<char, string> &s){
  char turn, next;
  for(turn = 'a'; s[turn].size() > 0; turn = next){
    next = s[turn][0];
    s[turn] = s[turn].erase(0,1);
  }
  return toupper(turn);
}

int main(){
  map<char, string> s;
  for(char c = 'a'; c <= 'c'; c++){
    cin >> s[c];
  }

  char result = getResult(s);
  cout << result << endl;
}