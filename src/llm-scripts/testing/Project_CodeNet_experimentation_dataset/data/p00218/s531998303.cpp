#include <iostream>
using namespace std;

int main() {
  while(1) {
    int n;
    cin >> n;
    if(n == 0) break;
    int pm[n], pe[n], pj[n];
    double average[n];
    double ave_me[n];
    for(int i = 0; i < n; i++) {
      cin >> pm[i] >> pe[i] >> pj[i];
      average[i] = (pm[i]+pe[i]+pj[i])/3.0;
      ave_me[i] = (pm[i]+pe[i])/2.0;
    }
    char grade[n];
    for(int i = 0; i < n; i++) {
      if(pm[i] == 100 || pe[i] == 100 || pj[i] == 100) {
	grade[i] = 'A';
      } else if(ave_me[i] >= 90) {
	grade[i] = 'A';
      } else if(average[i] >= 80) {
	grade[i] = 'A';
      } else if(average[i] >= 70) {
	grade[i] = 'B';
      } else if(average[i] >= 50 && (pm[i] >= 80 || pe[i] >= 80)) {
	grade[i] = 'B';
      } else {
	grade[i] = 'C';
      }
      cout << grade[i] << endl;
    }
  }
  return 0;
}