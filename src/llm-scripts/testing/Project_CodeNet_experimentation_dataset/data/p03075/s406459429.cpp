#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> A(5);
  int k;
  for(int &i:A)
    cin>>i;
  cin>>k;
  sort(A.begin(),A.end());
  if(A.at(4)-A.at(0)>k)
    cout<<":("<<endl;
  else
    cout<<"Yay!"<<endl;
}