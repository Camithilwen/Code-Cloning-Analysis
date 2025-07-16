#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;int i;
  for(i=1;i<S.size();i++)if(S.at(i-1)=='A'&&S.at(i)=='C')break;
  if(i==S.size())cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}