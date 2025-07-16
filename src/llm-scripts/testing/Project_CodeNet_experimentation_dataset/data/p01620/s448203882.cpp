#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)
#define F first
#define S second

using namespace std;
int n,key[110];
string s;
char alp[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
              'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int main() {
  while(1){
    cin>>n;
    if(n==0) break;
    REP(i,0,n) cin>>key[i];
    cin>>s;
    REP(i,0,s.size()){
      int pos=-1;
      REP(j,0,52){
        if(alp[j]==s[i]){
          pos = j;
          break;
        }
      }
      cout<<alp[(pos - key[i%n] + 52*10000)%52];
    }
    cout<<endl;
  }
  return 0;
}