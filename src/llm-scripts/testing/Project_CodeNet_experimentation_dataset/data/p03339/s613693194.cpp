#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>data(N);
  for(int i;i<N;i++){
    char a;
    cin >> a;
    if(a=='W') data.at(i)=0;
    else data.at(i)=1;
  }
  vector<int>r(N);
  int one=0;
  for(int i=1;i<N;i++){
    one+=data.at(i);
  }
  r.at(0)=one;
  for(int i=1;i<N;i++){
    int a=0;
    if(data.at(i)==1) a--;
    if(data.at(i-1)==0) a++;
    r.at(i)=r.at(i-1)+a;
  }
  sort(r.begin(),r.end());
  
  cout << r.at(0) << endl;
}