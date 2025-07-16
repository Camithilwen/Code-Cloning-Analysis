#include <bits/stdc++.h>
using namespace std;

struct StQuery
{
  StQuery() : m_nLeft(0), m_nRigt(0) { }

  int m_nLeft;
  int m_nRigt;
};

void input(string& rsStr, vector<StQuery>& rvoQuery)
{
  int nStrSiz, nQuerySiz;
  cin >> nStrSiz >> nQuerySiz;
  rvoQuery.resize(nQuerySiz);

  cin >> rsStr;
  
  for (StQuery& roQuery : rvoQuery)
    cin >> roQuery.m_nLeft >> roQuery.m_nRigt;
}

void calcSubStrACCnt(string sStr, const vector<StQuery>& cnrvoQuery)
{
  vector<int> vnCumlSum(sStr.size() + 1);      // 累積和

  //vnCumlSum_ix 0 1 2 3 4 5 6 7 8
  //sStr_pos      1 2 3 4 5 6 7 8
  //sStr          A C A C T A C G
  //sStr_ix       0 1 2 3 4 5 6 7
  for (int nBgn = 0; nBgn < vnCumlSum.size() - 1; nBgn++)
  {
    vnCumlSum[ nBgn + 2 ] = vnCumlSum[ nBgn + 1 ];
    if (sStr[nBgn] == 'A' && sStr[nBgn + 1] == 'C')
      vnCumlSum[ nBgn + 2 ]++;
  }

 for (int i = 0; i < cnrvoQuery.size(); i++)
  {
    cout << vnCumlSum[ cnrvoQuery[i].m_nRigt ] - vnCumlSum[ cnrvoQuery[i].m_nLeft ];
    cout << endl; 
  }
}
 
int main()
{
  string sStr;
  vector<StQuery> voQuery;

  input(sStr, voQuery);
  calcSubStrACCnt(sStr, voQuery);

  return 0;
}