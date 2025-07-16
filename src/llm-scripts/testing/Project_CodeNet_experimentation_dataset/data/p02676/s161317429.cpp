#include<iostream>
#include<string>
using namespace std;
int main(){
  int k;
  cin>>k;
  string s,S;
  cin>>s;
  if(s.length()<=k)
    cout<<s;
  else{
    for(int i=0;i<k;i++){
    	cout<<s[i];
	}
  cout<<"...";
}
}
  