#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(int)(n);i++)
#define FORR(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define pb(a) push_back(a)
#define ZERO(a) memset(a,0,sizeof(a))
#define len(a) sizeof(a)
#define ll long long
#define INF 1<<29
#define MAX 
using namespace std;

void solve(){
 string s;
 cin>>s;
 int ma=0;
 FOR(i,s.size()){
  if(s[i]!='O') continue;
  int O=i;
  while(O+1<s.size()&&s[O+1]=='O') O++;
  int J=i;
  while(J&&s[J-1]=='J') J--;
  int I=O;
  while(I+1<s.size()&&s[I+1]=='I') I++;
  if(I-O-1>=O-i&&i-1-J>=O-i) ma=max(ma,O-i+1);
  i=I;
 }
 cout<<ma<<endl;
}

int main(){
 solve();
 return 0;
}