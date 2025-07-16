#include <iostream>
#include <regex>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  int A, B;
  string S;
  cin >> A >> B >> S;
  regex rx(R"([0-9]{)" + to_string(A) + R"(}-[0-9]{)" + to_string(B) + R"(})");
  if (regex_match(S, rx)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}