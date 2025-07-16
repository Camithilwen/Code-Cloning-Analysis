#include<bits/stdc++.h>
using namespace std;

int main(){

 string a,b,c;
 cin >> a >> b >> c;

 int A, B, C;
  A = a.size()-1;
  B = b.size()-1;
  C = c.size()-1;
  
  if(a.at(A)==b.at(0)&& b.at(B)==c.at(0))
 	cout << "YES" <<endl;
  else
    cout <<"NO" <<endl;
}