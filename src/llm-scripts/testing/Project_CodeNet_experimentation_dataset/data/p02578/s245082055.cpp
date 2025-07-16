#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  long long count;
  cin >> N;
  vector<int> a(N);
  count = 0;
  
  for(int i = 0;i < N;i++){
     cin >> a.at(i);
    if(i > 0){
      if(a.at(i-1) > a.at(i)){
        count += a.at(i-1) - a.at(i);
        a.at(i) = a.at(i-1);
      }
    }
  }
  cout << count << endl;
  
}