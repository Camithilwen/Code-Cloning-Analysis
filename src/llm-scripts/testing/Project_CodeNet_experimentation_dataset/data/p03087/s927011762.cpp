#include <bits/stdc++.h>
using namespace std;

struct StQuery
{
  StQuery() : m_nLeft(0), m_nRigt(0) { }

  int m_nLeft;
  int m_nRigt;
};

void fnInput(string& rsStr, vector<StQuery>& rvoQuery)
{
  int nStrSiz, nQuerySiz;
  cin >> nStrSiz >> nQuerySiz;
  rvoQuery.resize(nQuerySiz);

  cin >> rsStr;
  
  for (StQuery& roQuery : rvoQuery)
    cin >> roQuery.m_nLeft >> roQuery.m_nRigt;
}

void fnSubStrACCnt(string sStr, const vector<StQuery>& cnrvoQuery)
{
  const string cnsAC = "AC";
  int nACCnt = 0;
  vector<int> vnACCnt(sStr.size());

  for (int nBgn = 0; nBgn < vnACCnt.size() - 1; nBgn++)
  {
    if (sStr.substr(nBgn, 2) == cnsAC) nACCnt++;
    vnACCnt[ nBgn + 1 ] = nACCnt;
  }

  for (int i = 0; i < cnrvoQuery.size(); i++)
  {
    cout << vnACCnt[ cnrvoQuery[i].m_nRigt - 1 ] - vnACCnt[ cnrvoQuery[i].m_nLeft - 1];
    cout << endl; 
  }
}
 
int main()
{
  string sStr;
  vector<StQuery> voQuery;

  fnInput(sStr, voQuery);
  fnSubStrACCnt(sStr, voQuery);

  return 0;
}