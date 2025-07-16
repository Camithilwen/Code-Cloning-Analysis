#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  int b;
  cin>>a>>b;
  for(int i=0;i<a.size();i+=b){
    cout<<a.at(i);
  }
  cout<<endl;
}