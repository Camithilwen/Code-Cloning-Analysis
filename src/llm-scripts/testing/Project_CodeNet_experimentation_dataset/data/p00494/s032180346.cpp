#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
  string str;
  while(cin >> str){
    vector<char> v;
    int ci, cj, co;
    int lv = 0;
    for(int i=0; i<str.size(); ++i) v.push_back(str[i]);
    ci = 0;
    cj = 0;
    co = 0;
    for(int i=0; i<v.size(); ++i){
      if(v[i] == 'J'){
	++cj;
      }else if(cj>0){
	for(;i<v.size(); ++i){
	  if(v[i] == 'O'){
	    ++co;
	  }else if(co>0){
	    for(;i<v.size(); ++i){
	      if(v[i] == 'I'){
		++ci;
	      }
	      if(v[i] != 'I' || i == v.size()-1){
		if(co <= cj && co <= ci && co > lv)lv = co;
		co = 0;
		ci = 0;
		cj = 0;
		//cout << "cj:co:ci:i = " <<cj<<":"<<co<<":"<<ci<<":"<<i<< endl;
 		//--i;
		break;
	      }
	    }
	  }
	  if(v[i]!='O'){
	    co = 0;
	    cj = 0;
	    ci = 0;
	    i -=1;
	    break;
	  }
	}
      }
    }
    //cout << "-----------------------------"<< endl;
    cout << lv << endl;
  }
}
  

