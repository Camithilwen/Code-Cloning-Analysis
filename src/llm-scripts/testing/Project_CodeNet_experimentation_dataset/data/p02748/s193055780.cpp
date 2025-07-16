#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
  int A,B,m;
  cin >> A >> B >> m;
  int a[A],b[B];
  int mina=999999;
  int minb=999999;

  int xyc[m][3];

  for (int i = 0; i < A; i++)
  {
    cin >> a[i];
    if (a[i] < mina)
    {
      mina=a[i];
    }
  }
  
  for (int i = 0; i < B; i++)
  {
    cin >> b[i];
    if (b[i] < minb)
    {
      minb=b[i];
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> xyc[i][j];
    }
  }

  int minsum=mina+minb;
  
  // yes
  for (int i = 0; i < m; i++)
  {
    int sum = a[xyc[i][0]-1] + b[xyc[i][1]-1] - xyc[i][2];
    if (sum<minsum)
    {
      minsum=sum;
    } 
  }

  cout << minsum << "\n";

  return 0;
}