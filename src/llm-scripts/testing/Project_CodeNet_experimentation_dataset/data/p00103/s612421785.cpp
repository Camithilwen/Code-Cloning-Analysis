#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    int score = 0;
    int out = 0;

    int first = 0;
    int second = 0;
    int third = 0;

    while(1) {
      string str;
      cin >> str;
      if(str == "HIT") {
	score += third;
	third = second;
	second = first;
	first = 1;
      } else if(str == "HOMERUN") {
	score += first + second + third + 1;
	first = second = third = 0;
      } else if(str == "OUT") {
	out++;
      }

      if(out == 3) {
	cout << score << endl;
	break;
      }
    }
  }
  return 0;
}