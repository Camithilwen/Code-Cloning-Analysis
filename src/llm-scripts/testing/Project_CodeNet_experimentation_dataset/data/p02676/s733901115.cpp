#include<bits/stdc++.h>
using namespace std;
int main(){
  int k;
  string s;
  cin >> k >> s;
  int len;
  len=s.size();
  if(len<=k){
    cout << s << endl;
    return 0;
  }else{
    for(int i=0;i<k;i++){
      cout << s.at(i);
    }
  }
  cout << "..." << endl;
}