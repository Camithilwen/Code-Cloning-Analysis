#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
 int N,X,T;
 cin >> N >> X >> T;
 int ans = N/X;
 double mod = N%X;
 if(mod > 0){
 ans = ans + 1;
 }
  ans = ans * T;
 cout << ans << endl;
}