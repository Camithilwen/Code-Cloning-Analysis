#include <iostream>
#include <vector>
#include <utility>
using namespace  std;

void fnInput(int &rnMaxSiz, vector<int> &rvnNum)
{
  cin >> rnMaxSiz;

  rvnNum.resize(rnMaxSiz);
  for (int i = 0; i < rnMaxSiz; i++)
    cin >> rvnNum[i];
}

void fnPartition(vector<int> &rvnNum, int nStart, int nEnd, int &nCur)
{
  for (int i = nStart; i < nEnd; i++)
    if (rvnNum[i] <= rvnNum[nEnd])
      swap(rvnNum[nCur++], rvnNum[i]);

  swap(rvnNum[nCur], rvnNum[nEnd]);
}

void fnResult(const vector<int> &cnrvnNum, int nCur)
{
  for (int i = 0; i < cnrvnNum.size(); i++)
  {
    if (i)  cout << " ";
    if (i == nCur) cout << "[";
    cout << cnrvnNum[i];
    if (i == nCur) cout << "]";
  }
  cout << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int nMaxSiz;
  vector<int> vnNum;

  fnInput(nMaxSiz, vnNum);
  int nStart = 0;
  int nEnd = vnNum.size() - 1;
  int nCur = nStart;

  fnPartition(vnNum, nStart, nEnd, nCur);
  fnResult(vnNum, nCur);

  return 0;
}