#include<iostream>
using namespace std;
int main(){
  char str[20];
  cin>>str;
  for(int i=20;i>0;i--)
    cout<<str[i-1];
  cout<<endl;
  return 0;
}