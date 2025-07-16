#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(string str){
  string rstr = str;
  reverse(str.begin(), str.end());

  return rstr == str;
}

int main(){
  int A, B, ans = 0;
  cin >> A >> B;

  for (int i = A; i <= B; i++){
    if (is_palindrome(to_string(i))) ans++;
  }
  
  printf("%d\n", ans);
}
