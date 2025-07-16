/// However long the night,
///     The dawn will break
/// ICPC next year

#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+5 ;

int n ,a[N] ,b[N] ;
vector<int> xorA ,xorB ;

int nn ,mm ,pat[N], str[N];

int F[N];

int getNextLen(int len, int c){
  while(len && c != pat[len])
    len = F[len-1];
  if(c == pat[len]) ++len;
  return len;
}

void computeF(){
  for(int i = 1 ; i<nn ; ++i)
    F[i] = getNextLen(F[i-1], pat[i]);
}

vector<int> search(){
  int len = 0;
  vector<int> res;
  for(int i = 0 ; i<mm ; ++i){
    len = getNextLen(len, str[i]);
    if(len==nn){
        res.push_back(i-len+1);
    }
  }
  return res;
}


int main(){
    memset(pat,-1,sizeof pat);
    memset(str,-1,sizeof str);
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",a+i);
    for(int i=0;i<n;++i) scanf("%d",b+i);
    for(int i=0;i<n;++i){
        xorA.push_back(a[i]^a[(i+1)%n]);
        xorB.push_back(b[i]^b[(i+1)%n]);
    }
    for(int i=n;i<n+n+n;++i) xorA.push_back(xorA[i-n]);

    for(int i=0;i<xorA.size();++i) str[i] = xorA[i] ;
    for(int i=0;i<xorB.size();++i) pat[i] = xorB[i] ;
    mm = xorA.size() ;
    nn = xorB.size() ;
    computeF() ;
    auto v = search() ;

    for(auto go:v){
        if(go>=n) break ;
        int x = a[go]^b[0] ;
        printf("%d %d\n",go,x);
    }
    return 0;
}
