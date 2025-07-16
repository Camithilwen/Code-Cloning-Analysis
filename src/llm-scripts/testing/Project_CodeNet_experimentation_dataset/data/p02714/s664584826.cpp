#include <iostream>
#include <string>
#include <set>

using namespace std;

void input(int& N, set<int>& R_INDEX, set<int>& G_INDEX, set<int>& B_INDEX)
{
  char c;
  for (int i= 0; i < N; i++){
    cin >> c;
    switch(c){
    case 'R':
      R_INDEX.insert(i);
      break;
    case 'G':
      G_INDEX.insert(i);
      break;
    case 'B':
      B_INDEX.insert(i);
      break;
    }
  }
}

long long int findsetnum(set<int>& R_INDEX, set<int>& G_INDEX, set<int>& B_INDEX)
{
  long long int sum = 0;
  int a, b, c;
  set<int>::iterator R_iter, G_iter;
  for (R_iter = R_INDEX.begin(); R_iter != R_INDEX.end(); R_iter++)
    for (G_iter = G_INDEX.begin(); G_iter != G_INDEX.end(); G_iter++){
      a = (B_INDEX.find(2 * (*G_iter) - *R_iter) == B_INDEX.end())? 0 : 1;
      b = (B_INDEX.find(2 * (*R_iter) - *G_iter) == B_INDEX.end())? 0 : 1;
      c = (B_INDEX.find((*G_iter + *R_iter) / 2) == B_INDEX.end() || (*G_iter + *R_iter) % 2 != 0)? 0 : 1;
      sum += (B_INDEX.size() - a - b - c);
    }
  return sum;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  set<int> R_INDEX, G_INDEX, B_INDEX;
  input(N, R_INDEX, G_INDEX, B_INDEX);
  cout << findsetnum(R_INDEX, G_INDEX, B_INDEX) << '\n';
  return 0;
}
