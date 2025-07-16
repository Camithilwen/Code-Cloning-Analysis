#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int main()
{
  char s[81];

  while(gets(s) != NULL){

    int len = strlen(s);
    
    if(strstr(s,"this") || strstr(s,"that") || strstr(s,"the")){
      cout << s << endl;
      continue;
    }
    
    for(int i = 0;i < 'z' - 'a';i++){
      for(int j = 0;j < len;j++){
	if(s[j] >= 'a' && s[j] <= 'z'){
	  if(s[j]+1 > 'z'){
	    s[j] = 'a';
	  }
	  else{
	    s[j]++; 
	  }
	}
      }
      if(strstr(s,"this") || strstr(s,"that") || strstr(s,"the")){
	cout << s << endl;
	break;
      }
    }
  }
}