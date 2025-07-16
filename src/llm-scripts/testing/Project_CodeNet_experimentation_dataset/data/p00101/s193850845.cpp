#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
/*
vector<string> split(string& s, char x){ // O(s.length())
  int i;
  vector<string> res(1);

  int word = 0;
  rep(i,s.size()){
    if(s[i] != x) res[word].push_back(s[i]);
    else if(i != 0 && i != s.size()-1){
      word++;
      res.push_back("");
    }
  }

  return res;
}
*/
int main(){
  int i,j,N;

  scanf("%d\n",&N);
  rep(i,N){
    string in;
    getline(cin,in);
/*
    vector<string> sp = split(in,' ');
    rep(j,sp.size()){
      if(sp[j] == "Hoshino") sp[j] = "Hoshina";
      if(sp[j] == "Hoshino.") sp[j] = "Hoshina.";
      cout << sp[j];
      if(j != sp.size()-1) cout << ' '; else cout << endl;
    }
  */
    int found = -1;
    while((found = in.find("Hoshino")) != -1) in[found + 6] = 'a';
    cout << in << endl;
  }

  return 0;
}