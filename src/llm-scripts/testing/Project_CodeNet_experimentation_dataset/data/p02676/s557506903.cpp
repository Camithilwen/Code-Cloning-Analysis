#include<bits/stdc++.h>

using namespace std;

int main(){

  int k;
  string str;
  cin>>k;
  cin.ignore();
  getline(cin,str);
  int len = str.length();
  if(len>k){
   str[k]='.';
    k++;
   str[k] ='.';
    k++;
    str[k]='.';
    for(int i=0;i<k+1;i++)
      cout<<str[i];
  }
  else 
    cout<<str;

}