#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void read_separated_string(vector<int> &v, string str) {
  istringstream istr(str);
  string tmp;
  while (getline(istr, tmp, ' ')) {
    v.push_back(stoi(tmp));
  }
}

int main() {
  int N, Q;
  vector<int> n;
  vector<int> q;
  string str;
  cin >> N; cin.ignore();
  getline(cin, str);
  read_separated_string(n, str);
  cin >> Q; cin.ignore();
  getline(cin, str);
  read_separated_string(q, str);

  int count = 0;
  for (int i : q) {
    for (int j : n) {
      if (i == j) {
        count++;
        break;
      }
    }
  }
  cout << count << endl;
}