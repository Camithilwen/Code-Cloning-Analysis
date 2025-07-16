#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  string S;
  cin >> S;
  vector<int> v={0};
  for (int i = 0; i < (int)S.size(); i++) {
    if (S[i] == 'S') {
      v.push_back(0);
    } else {
      v[(int)v.size()-1]++;
    }
  }
  cout << *max_element(v.begin(), v.end()) << endl;
  return 0;
}