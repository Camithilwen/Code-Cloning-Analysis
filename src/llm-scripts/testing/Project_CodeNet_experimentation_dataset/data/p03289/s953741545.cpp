#include <iostream>
#include <regex>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  regex rx(R"(^A[a-z][a-z]*?C[a-z]*?[a-z]$)");
  if (regex_match(S, rx)) {
    printf("AC\n");
  } else {
    printf("WA\n");
  }
}
