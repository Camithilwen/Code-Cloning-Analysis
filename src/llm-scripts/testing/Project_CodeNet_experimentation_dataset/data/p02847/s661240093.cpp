#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin>>S;
  int Ans=0;
  if(S=="SUN"){Ans=7;}
  else if(S=="MON"){Ans=6;}
  else if(S=="TUE"){Ans=5;}
  else if(S=="WED"){Ans=4;}
  else if(S=="THU"){Ans=3;}
  else if(S=="FRI"){Ans=2;}
  else {Ans=1;}
  cout<<Ans<<endl;
}