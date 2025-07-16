#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep1(i,n) for(long long i=1;i<=(long long)(n);i++)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main() {
  string S;
  char s;
  cin>>S;
  if(S.size()==2){cout<<S<<endl;}
  else{s=S[0]; S[0]=S[2]; S[2]=s; cout<<S<<endl;}
}