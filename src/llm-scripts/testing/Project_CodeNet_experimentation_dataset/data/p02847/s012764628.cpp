#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
  string s;cin>>s;
  string a[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
  for(int i=0;i<7;i++){
  	if( s!="SUN" && a[i]==s){
  		cout<<(6-i);
  	}
  	else if(s=="SUN"){
  		cout<<7;
  		break;
  }
}
  return 0;
}
  