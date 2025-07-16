#include <bits/stdc++.h>
using namespace std;

void input(int& rnTrgSu, int& rnTrgKin)
{
  cin >> rnTrgSu >> rnTrgKin;
}

void searchCntl(int nTrgSu, int nTrgKin)
{
  for (int n10000 = 0; n10000 <= nTrgSu; ++n10000)
    for (int n5000 = 0; n5000 <= (nTrgSu - n10000); ++n5000)
    {
      int n1000 = nTrgSu - n10000 - n5000;
      if (nTrgKin == 10000 * n10000 + 5000 * n5000 + 1000 * n1000)
      {
        cout << n10000 << " " << n5000 << " " << n1000 << endl;
        return;
      }
    }
  cout << -1 << " " << -1 << " " << -1 << endl;
}

int main()
{
  int nTrgSu, nTrgKin;
  
  input(nTrgSu, nTrgKin);
  searchCntl(nTrgSu, nTrgKin);

  return 0;
}