#include <bits/stdc++.h>
using namespace std;

int soredake(int point, int kazu, int bonasu, int goal) {
  int tokukazu = goal / point;
  if (goal % point > 0) {
    tokukazu++;
  }
  if (tokukazu > kazu) {
    tokukazu = kazu;
  }
  return tokukazu;
}

int search(vector<vector<int>> questions, int goal) {

  int minimum = 0;
  for (int i = 0; i < questions.size(); i++) {
    minimum += questions.at(i).at(1);
  }
  for (int i = 0; i < questions.size(); i++) {
    int point = questions.at(i).at(0);
    int kazu = questions.at(i).at(1);
    int bonasu = questions.at(i).at(2);
    int goukei = questions.at(i).at(3);

    vector<vector<int>> q = questions;
    q.erase(q.begin() + i);
    if (goukei < goal) {
      int nokori = search(q, goal - goukei) + kazu;
      if (nokori < minimum) {
        minimum = nokori;
      }
    } else {
      int nokori = soredake(point, kazu, bonasu, goal);
      if (nokori < minimum) {
        minimum = nokori;
      }
    }
  }
  return minimum;
}

int main() {
  int d, g;
  cin >> d >> g;

  vector<vector<int>> questions(d, vector<int>(4));
  for (int i = 0; i < d; i++) {
    questions.at(i).at(0) = 100 * (i + 1);
    cin >> questions.at(i).at(1);
    cin >> questions.at(i).at(2);
    questions.at(i).at(3) =
        questions.at(i).at(0) * questions.at(i).at(1) + questions.at(i).at(2);
  }

  cout << search(questions, g) << endl;
}
