#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
using namespace std;
#define INF (1<<20)
map<string,int> m;
vector<int> num;
main(){
  m["I"]=1;
  m["II"]=2;
  m["III"]=3;
  m["IV"]=4;
  m["V"]=5;
  m["VI"]=6;
  m["VII"]=7;
  m["VIII"]=8;
  m["IX"]=9;
  m["X"]=10;

  m["XI"]=11;
  m["XII"]=12;
  m["XIII"]=13;
  m["XIV"]=14;
  m["XV"]=15;
  m["XVI"]=16;
  m["XVII"]=17;
  m["XVIII"]=18;
  m["XIX"]=19;
  m["XX"]=20;

  m["XXX"]=30;
  m["XL"]=40;
  m["L"]=50;
  m["LX"]=60;
  m["LXX"]=70;
  m["LXXX"]=80;
  m["XC"]=90;
  m["C"]=100;
  m["D"]=500;
  m["M"]=1000;
  string str;
  while(cin >> str){
    int res=0;
    int tmp;
    for(int i=0;i<(int)str.size();i++){
      for(int j=4;j>0;j--){
	if(i+j>str.size()) continue;
	if(m[str.substr(i,j)]>0){
	  num.push_back(m[str.substr(i,j)]);
	  i+=(j-1);
	  break;
	}
      }
    }
    int i=0;
    for(i=0;i<num.size()-1;i++){
      // cout << num[i] << endl;
      if(num[i]>=num[i+1]) res += num[i];
      else{ res += (num[i+1]-num[i]); i++;}
    }
    
    //   cout << num.back() << endl;
    if(i==num.size()-1)
      res += num.back();
    cout << res << endl;
    num.clear();
  }
}