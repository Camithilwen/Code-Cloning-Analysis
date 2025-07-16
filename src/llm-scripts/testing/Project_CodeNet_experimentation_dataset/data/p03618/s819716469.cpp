#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;cin>>S;
  vector<long long>v(26);
  for(int X=0;X<S.size();X++){
    v[S[X]-97]++;
  }
  sort(v.begin(),v.end());
  long long H=0;
  for(int X=25;X>=0;X--){
    if(v[X]>1){
      H+=v[X]*(v[X]-1)/2;
    }
    else{
      break;
    }
  }
  cout<<S.size()*(S.size()-1)/2-H+1<<endl;
}