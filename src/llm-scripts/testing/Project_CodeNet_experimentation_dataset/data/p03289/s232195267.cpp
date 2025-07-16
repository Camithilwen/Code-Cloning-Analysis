#include<bits/stdc++.h>
using namespace std;



int main()
{
  string S;cin>>S;
  if(S[0]!='A'||S.size()<3){printf("WA");return 0;}
  int countc=0;
  for(int i=2;i<S.size()-1;i++)if(S[i]=='C')countc++;
  if(countc!=1){printf("WA");return 0;}
  for(int i=1;i<S.size();i++)if(S[i]!='A'&&S[i]!='C'&&S[i]-'A'>=0&&S[i]-'A'<=26){printf("WA");return 0;}
  printf("AC");
}