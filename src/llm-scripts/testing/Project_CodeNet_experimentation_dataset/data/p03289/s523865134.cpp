#include <iostream>
#include <string>
using namespace std;
int main()
{
  string S;
  cin >> S;
  bool ans = true;
  //1
  if (S[0]!='A') ans = false;
  
  //2
  int Ccnt = 0;
  for  (int i = 2; i <= S.length()-2; i++) {
    if (S[i]=='C') Ccnt++;
  }
  if (Ccnt!=1) ans = false;
  
  //3
  int CpCnt = 0;
  for (int i = 0; i < S.length(); i++) {
    if (('A'<= S[i]) && (S[i] <= 'Z')) CpCnt++;
  }
  if (CpCnt != 2) ans = false;
  
  if (ans) cout << "AC" << endl;
  else cout << "WA" << endl;
  return 0;
}
