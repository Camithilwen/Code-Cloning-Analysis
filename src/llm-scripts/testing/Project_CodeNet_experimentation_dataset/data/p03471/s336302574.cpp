#include <bits/stdc++.h>
using namespace std;

void input(int& rnTrgSu, int& rnTrgKin)
{
  cin >> rnTrgSu >> rnTrgKin;
}

int dfs(int nPos, int nTrgSu, int nTrgKin, vector<int>& rvnMoneyCnt)
{
  const vector<int> cnvnMoney{10000, 5000, 1000};

  if (nTrgSu == 0 && nTrgKin == 0) return  1;
  if (nTrgKin <  0)                return -1;
  if (nPos == rvnMoneyCnt.size())  return  0;

  if (nPos == rvnMoneyCnt.size() - 1)
  {
    rvnMoneyCnt[nPos] = nTrgSu;
    return dfs(nPos + 1, 0, nTrgKin - cnvnMoney[nPos] * nTrgSu, rvnMoneyCnt);
  }
  else
    for (int i = 0; i <= nTrgSu; i++)
    {
      rvnMoneyCnt[nPos] = i;
      for (int i = nPos + 1; i < rvnMoneyCnt.size(); i++)
        rvnMoneyCnt[i] = 0;

      int nReslt = dfs(nPos + 1, nTrgSu - i, nTrgKin - cnvnMoney[nPos] * i, rvnMoneyCnt);
      if      (nReslt ==  1)  return 1;
      else if (nReslt == -1)  break;
    }

  return 0;
}

void searchCntl(int nTrgSu, int nTrgKin)
{
  vector<int> vnMoneyCnt(3);

  if ( dfs(0, nTrgSu, nTrgKin, vnMoneyCnt) )
  {
    for (int i = 0; i < vnMoneyCnt.size(); i++)
    {
      if ( i )  cout << " ";
      cout << vnMoneyCnt[i];
    }
    cout << endl;
  }
  else
    cout << -1 << " " << -1 << " " << -1 << endl;
}

int main()
{
  int nTrgSu, nTrgKin;
  
  input(nTrgSu, nTrgKin);
  searchCntl(nTrgSu, nTrgKin);

  return 0;
}