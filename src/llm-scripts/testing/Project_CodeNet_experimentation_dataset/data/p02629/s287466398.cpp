#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  long long int n=0;
  cin >> n;
  long long int ans=0;
  int i=0;
  int amari=0;
  vector<int>dog;
  while(n>0){
    if(n%26 == 0){
      amari=n%26;
      dog.push_back(amari);
      n/=26;
      n--;
      continue;
    }
    amari=n%26;
    dog.push_back(amari);
    n/=26;
  }
  reverse(begin(dog),end(dog));
  for(int i=0;i<(dog.size());i++){
    char c;
    if(dog.at(i) == 0){
      cout << "z";
      continue;
    }
    c = dog.at(i)+96;
    cout << c;
  }
  cout << endl;
}