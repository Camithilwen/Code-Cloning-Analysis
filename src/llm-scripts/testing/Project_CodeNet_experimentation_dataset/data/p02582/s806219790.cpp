#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  
  if(S == "SSS") cout << "0" << endl;
  else if(S == "RRR") cout << "3" << endl;
  else if(S == "SRR" || S == "RRS") cout << "2" << endl;
  else cout << "1" << endl;
}