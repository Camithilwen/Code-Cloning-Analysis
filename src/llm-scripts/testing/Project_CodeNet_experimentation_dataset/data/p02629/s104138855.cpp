#include<bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin >> N;
  string S="";
  while(N){
    N--;
    int A=N%26;
    N/=26;
    char a='a'+A;
    S.push_back(a);
  }
  reverse(S.begin(),S.end());
  cout << S << endl;
}