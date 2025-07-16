#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
int main(){
  int n;
  while(cin >> n,n){
    vector<int> key(n);
    rep(i,n) cin >> key[i];
    int x = 0;
    string str;
    cin >> str;
    while(key.size() < str.size()){
      if(x==key.size()) x = 0;
      key.push_back(key[x]);
      x++;
    }
    rep(i,str.size()){
      rep(j,key[i]){
        if(str[i]=='a') str[i] = 'Z';
        else if(str[i]=='A') str[i] = 'z';
        else str[i]--;
      }
    }
    rep(i,str.size()) cout << str[i];
    cout << endl;
  }
  return 0;
}

