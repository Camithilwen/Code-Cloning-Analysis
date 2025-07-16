#include <bits/stdc++.h>
using namespace std;

void input(int& rnTrgSu, int& rnTrgKin)
{
  cin >> rnTrgSu >> rnTrgKin;
}

void searchMoney(int nTrgSu, int nTrgKin)
{
  vector<int> cnvnMoney{10000, 5000, 1000};

  int nCalKin;
  int i, j;
  for (i = 0; i <= nTrgSu; i++)
  {
    for (j = 0; j <= (nTrgSu - i); j++)
    {
      nCalKin = nTrgKin;

      nCalKin -= cnvnMoney[0] * i;
      nCalKin -= cnvnMoney[1] * j;
      nCalKin -= cnvnMoney[2] * (nTrgSu - i - j);
      if ( !nCalKin )
        break;
    }
    if ( !nCalKin )
      break;
  }
  if ( !nCalKin )
    cout << i << " " << j << " " << (nTrgSu - i - j) << endl;
  else
    cout << -1 << " " << -1 << " " << -1 << endl;
}

int main()
{
  int nTrgSu, nTrgKin;
  
  input(nTrgSu, nTrgKin);
  searchMoney(nTrgSu, nTrgKin);

  return 0;
}