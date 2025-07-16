#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int n;
  cin >> n;
  vector<int> odd(100001);
  vector<int> even(100001);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (i % 2 == 0) {
      odd[v]++;
    } else {
      even[v]++;
    }
  }
  int oddMax = 0, evenMax = 0;
  int oddMax2 = 0, evenMax2 = 0;
  int oddMaxNum = 0, evenMaxNum = 0;
  for (int i = 0; i < 100001; i++) {
    if (odd[i] >= oddMax) {
      oddMax2 = oddMax;
      oddMax = odd[i];
      oddMaxNum = i;
    } else if(odd[i] > oddMax2){
      oddMax2 = odd[i];
    }
    if (even[i] >= evenMax) {
      evenMax2 = evenMax;
      evenMax = even[i];
      evenMaxNum = i;
    } else if(even[i] > evenMax2){
      evenMax2 = even[i];
    }
  }
  if (oddMaxNum == evenMaxNum) {
    if (oddMax - oddMax2 > evenMax - evenMax2) {
      evenMax = evenMax2;
    } else {
      oddMax = oddMax2;
    }
  }
  cout << n - oddMax - evenMax << endl;
}
