#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> b;
  while(n!=0){
    if(abs(n)%2==0)
      b.push_back(0);
    else{
      b.push_back(1);
      n--;
    }
    n/=-2;
  }
  if(b.empty())
    cout<<0;
  for(int i=b.size()-1;i>=0;i--)
    cout<<b.at(i);
  cout<<endl;
}