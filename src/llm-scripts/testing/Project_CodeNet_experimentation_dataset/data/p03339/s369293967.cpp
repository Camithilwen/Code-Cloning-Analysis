#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin>>N>>S;
  vector<int> a(N),b(N);
  int j=0;
  for(int i=0;i<N;i++){
    int k=0;
    if(S.at(i)=='E')
      k=1;
    j+=k;
    a.at(i)=j;
    b.at(i)=i+1-j;
  }
  j=a.at(N-1)-a.at(0);
  for(int i=1;i<N;i++){
    int k=b.at(i-1)+a.at(N-1)-a.at(i);
    j=min(j,k);
  }
  cout<<j<<endl;
}