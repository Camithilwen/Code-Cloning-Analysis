#include <iostream>
#include <string>

using namespace std;

int getvalue(char c){
  if(c == 'I'){
	  return 1;
	}else if(c == 'V'){
	  return 5;
	}else if(c == 'X'){
	  return 10;
	}else if(c == 'L'){
	  return 50;
	}else if(c == 'C'){
	  return 100;
	}else if(c == 'D'){
	  return 500;
	}else if(c == 'M'){
	  return 1000;
	}
  return -1;
}

int parseStr(string str){
  int ret=0;
  int now;
  int next;

  for(int i=0;i<str.size();i++){
	now = getvalue(str[i]);
	if(i != str.size() - 1){
	  next = getvalue(str[i+1]);
	}else{
	  next = -1;
	}
	
	if(now >= next){
	  ret += now;
	}else{
	  ret += next - now;
	  i++;
	}
  }
  return ret;
}

int main(void){
  string tmp;

  while(cin >> tmp){
	cout << parseStr(tmp) << endl;
  }
  
  return 0;
}