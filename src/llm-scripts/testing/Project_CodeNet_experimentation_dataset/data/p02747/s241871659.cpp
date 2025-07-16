#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s;
  cin >> s;
  int n=s.size();
  bool judge=true;
  if(n%2!=0){
    judge=false;
  }
  for(int i=0;i<n;i+=2){
    if(judge==false){
      break;
    }
    if(s.at(i)!='h'||s.at(i+1)!='i'){
      judge=false;
    }
  }
  if(judge){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}