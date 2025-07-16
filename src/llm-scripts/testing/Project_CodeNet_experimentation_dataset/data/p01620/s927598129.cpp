#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<char> init(){
  vector<char> data;
  for(int c='a'; c<='z'; ++c) data.push_back(c);
  for(int c='A'; c<='Z'; ++c) data.push_back(c);
  return data;
}

char solve(const char& c, int& x, const vector<char>& data){
  for(int i=0; i<data.size(); ++i){
    if(data[i] == c){
      int j = i-x;
      if(j < 0) j += data.size();
      return data[j];
    }
  }
}

int main(){
  int n;
  string s;
  vector<char> s_name = init();
  while(1){
    cin >> n;
    if(!n) break;
    vector<int> data(n, 0);
    for(int i=0; i<n; ++i) cin >> data[i];
    cin >> s;
    for(int i=0, j=0; i<s.size(); ++i){
      cout << solve(s[i], data[j], s_name);
      ++j;
      if(j == data.size()) j=0;
    }
    cout << endl;
  }
  return 0;
}