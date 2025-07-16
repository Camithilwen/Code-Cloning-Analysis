#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  cin >> a;
  if(a == 2){cout << -1 << endl;}
  else if(a == 3){cout << "aa." <<endl;
                 cout << "..a" <<endl;
                 cout << "..a" <<endl;}
  else{
    int c;
    c = (a/4-1)*4;
    for(int i = 0;i < c/2;i++){
      for(int j = 0;j < c;j++){
      if(j/2==i){cout << 'a';}
      else if(j==c-2*i-2){cout << 'c';}
      else if(j==c-2*i-1){cout << 'd';}
        else{cout << '.';}
      }
      for(int j = 0;j < a-c;j++){
        cout << '.';}
      cout << endl;
      for(int j = 0;j < c;j++){
      if(j/2==i){cout << 'b';}
      else if(j==c-2*i-2){cout << 'c';}
      else if(j==c-2*i-1){cout << 'd';}
        else{cout << '.';}
      }
      for(int j = 0;j < a-c;j++){
        cout << '.';}
       cout << endl;
    }
    int p = a-c;
    if(p == 4){
      for(int i = 0;i < c;i++){cout << '.';}
      cout << "aabc" << endl;
      for(int i = 0;i < c;i++){cout << '.';}
      cout << "ddbc" << endl;
      for(int i = 0;i < c;i++){cout << '.';}
      cout << "bcaa" << endl;
       for(int i = 0;i < c;i++){cout << '.';}
      cout << "bcdd" << endl;}
    else if(p == 5){
      for(int i = 0;i < c;i++){cout << '.';}cout << "aabbc" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "de..c" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "de..f" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "h.ggf" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "hiijj" << endl;}
    else if(p==6){
      for(int i = 0;i < c;i++){cout << '.';}cout << "aabxx." << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "c.b..z" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "cdd..z" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "xx.aab" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "..zc.b" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "..zcdd" << endl;}
    else{
      for(int i = 0;i < c;i++){cout << '.';}cout << "aa.bb.c" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << ".d..eec" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "fdg...." << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "f.g...h" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "...iijh" << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "zxx..j." << endl;
      for(int i = 0;i < c;i++){cout << '.';}cout << "z.mm.nn" << endl;}
  }
}