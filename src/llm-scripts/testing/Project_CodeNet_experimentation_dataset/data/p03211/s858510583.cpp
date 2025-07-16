#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>
 
int main() {
  
  string B;
  cin >> B;
  
  vector<char>vec(B.size());
  for(int i=0;i<B.size();i++){
    vec.at(i)=B.at(i);
  }
  int count=99999;
    for(int i=2 ;i<B.size();i++){
 int  A=vec.at(i-2)- '0',B=vec.at(i-1)- '0',C=vec.at(i)- '0';
 int D;
D=100*A+10*B+C;
 D=abs(753-D);
count=min(D,count);
  }
  cout << count <<endl;
  
}