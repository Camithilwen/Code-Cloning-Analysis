#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  vector<string> s(3);
  rep(i,3){
    cin >> s.at(i);
  }
  int c=0;
  vector<int> a(3,0);
  while(1){
    int cp=c;
    a.at(c)++;
    for(int i=0;i<3;i++){
      if(a.at(i)>s.at(i).size()){
        char d='A'+i;
        cout << d;
        return 0;
      }
    }
    c=s.at(cp).at(a.at(cp)-1)-'a';
  }
}
    