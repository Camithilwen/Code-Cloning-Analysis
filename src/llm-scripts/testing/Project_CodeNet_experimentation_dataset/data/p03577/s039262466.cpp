#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;  cin>>s;
  reverse(s.begin(),s.end());
  int n=s.size();
  string t = s.substr(8,n-8);
  reverse(t.begin(),t.end());
  cout << t << endl;
}