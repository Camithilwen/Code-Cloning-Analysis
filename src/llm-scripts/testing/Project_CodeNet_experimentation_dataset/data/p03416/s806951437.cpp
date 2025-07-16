#include <bits/stdc++.h>
using namespace std;
int func(int x){
  string y=to_string(x);
  vector<char> a(y.size());
  vector<char> b(y.size());
  for(int i=0;i<y.size();i++){
    a.at(i)=y.at(i);
    b.at(i)=y.at(i);
  }
  reverse(b.begin(),b.end());
  int c=0;
  for(int i=0;i<y.size();i++){
    if(a.at(i)!=b.at(i))
      c=1;
  }
  if(c==0)
    return 1;
  return 0;
  
}
int main(){
  int A,B,count=0;
  cin>>A>>B;
  for(int i=A;i<B+1;i++){
    if(func(i)==1)
      count++;
  }
  cout<<count<<endl;
  
}