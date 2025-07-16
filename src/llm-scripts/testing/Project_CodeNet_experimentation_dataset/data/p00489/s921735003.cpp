#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct comparator {
  int operator() (const pair<int, int>& l, const pair<int, int>& r) {
    return l.second < r.second;
  }
};

int main(int argc, char *argv[]) {
  // second = team's number                                                                                                                                               
  vector<pair<int, int> >team;
  int n, a, b, c, d, game;
  cin >> n;
  for (int i = 0; i < n; i++)
    team.push_back(pair<int, int>(0, i));
  game = n * (n-1) / 2;

  for (int i = 0; i < game; i++) {
    cin >> a >> b >> c >> d;
    if (c > d) {
      team[a-1].first += 3;
    } else if (c < d) {
      team[b-1].first += 3;
    } else {
      team[a-1].first++;
      team[b-1].first++;
    }
  }

  sort(team.rbegin(), team.rend());
  int points = -1, rank = 1;
  for (int i = 0; i < n; i++)
    if (team[i].first == points) {
      team[i].first = rank;
    } else {
      points = team[i].first;
      team[i].first = i+1;
      rank = i+1;
    }
  struct comparator comp;
  sort(team.begin(), team.end(), comp);

  for (int i = 0; i < n; i++)
    cout << team[i].first << endl;
  return 0;
}