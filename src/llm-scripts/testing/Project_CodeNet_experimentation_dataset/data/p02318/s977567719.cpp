#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int DP[1010][1010];

int main() {
  string A, B;
  cin >> A >> B;
  int LA = (int) A.size();
  int LB = (int) B.size();
  fill(&DP[0][0], &DP[0][0]+1010*1010, 0);
  for (auto i=-1; i<LA; i++) {
    for (auto j=-1; j<LB; j++) {
      if (i == -1) {
        DP[i+1][j+1] = j+1;
      } else if (j == -1) {
        DP[i+1][j+1] = i+1;
      } else if (A[i] == B[j]) {
        DP[i+1][j+1] = DP[i][j];
      } else {
        // A[i] と B[j] が異なるならば、
        // B[j]を挿入するか、A[i]を削除するか、A[i]をB[j]に置換するか
        // のどれかは必ず実行しなくてはならない。
        // 残りの編集作業回数は、それぞれDP[i+1][j]、DP[i][j+1]、DP[i][j]
        // となる。それぞれが最善である例をつくることができる。
        DP[i+1][j+1] = min({DP[i+1][j], DP[i][j+1], DP[i][j]}) + 1;
      }
    }
  }
  cout << DP[LA][LB] << endl;
}