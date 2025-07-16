#include <iostream>

#define MAX 1000

using namespace std;

class Contest {
public:
  Contest() {}
  Contest(int _id, int _cost, int _vote) {
    id = _id;
    cost = _cost;
    vote = _vote;
  }

  bool compare_cost(int _cost) {
    return cost <= _cost;
  }

  bool compare_vote(int _vote) {
    return vote < _vote;
  }

  void output_id() {
    cout << id << endl;
  }

  void voting(int _vote) {
    vote += _vote;
  }

  int getVote() {
    return vote;
  }

private:
  int id, cost, vote;
};


int main()
{
  int n, m;
  cin >> n >> m;

  Contest *contests = new Contest[MAX];
  int cost;
  for(int i = 0; i < n; i += 1){
    cin >> cost;
    contests[i] = Contest(i+1, cost, 0);
  }

  for(int i = 0; i < m; i += 1) {
    cin >> cost;

    for(int j = 0; j < n; j += 1) {
      if(contests[j].compare_cost(cost)){
	contests[j].voting(1);
	break;
      }
    }
  }

  Contest contest = contests[0];
  for(int i = 1; i < n; i += 1) {
    if(contest.compare_vote(contests[i].getVote())){
      contest = contests[i];
    }
  }

  contest.output_id();

  delete[] contests;

  return 0;
}