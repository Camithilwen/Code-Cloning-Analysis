#include<iostream>
#include<string>
using namespace std;
int main(){
  string key;
  while(getline(cin,key)){
    if(key.size() > 80){
      break;
    }
    for(int j=0; j<26; j++){
      for(int i=0; i<key.size(); i++){
	if(key[i] >= 'a' && key[i] <= 'z'){
	  if(key[i] == 'z')
	    key[i] = 'a';
	  else
	    key[i] += 1;
	}
      }
      if(key.find("the") != string::npos || key.find("this") != string::npos || key.find("that") != string::npos){
	cout << key << endl;
      }
    }
  }
  return 0;
}