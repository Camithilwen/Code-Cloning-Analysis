#include<bits/stdc++.h>
using namespace std; 
int main(){
  string S; cin>>S;
  if(S.size()==2)
    cout<<S<<endl;
  else
    cout<<S.at(2)<<S.at(1)<<S.at(0)<<endl;
}