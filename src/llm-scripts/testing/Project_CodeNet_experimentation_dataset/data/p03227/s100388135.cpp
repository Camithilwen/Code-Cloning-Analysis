#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int size = s.size();
  if(size==2){
    cout << s << endl;
  }else{
    cout << s.at(2) << s.at(1) <<s.at(0) << endl;
  }
}