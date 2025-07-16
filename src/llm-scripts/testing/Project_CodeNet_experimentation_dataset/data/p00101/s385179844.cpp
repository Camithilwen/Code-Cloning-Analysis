#include<string>
#include<iostream>
using namespace std;

string replaceAll(string s, string f, string t) {
  string r;
  for (int p = 0; (p = s.find(f)) != s.npos; ) {
    r += s.substr(0, p) + t;
    s = s.substr(p + f.size());
  }
  return r + s;
}

int main(){
  string s;
  int n;
  cin>>n;
  getline(cin,s);
  while(n--){
    getline(cin,s);
    cout<<replaceAll(s,string("Hoshino"),string("Hoshina"))<<endl;
  }
}