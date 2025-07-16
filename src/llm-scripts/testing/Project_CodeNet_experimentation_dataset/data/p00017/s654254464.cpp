#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>

//メイン関数
int main()
{
  char str[81];
   while(fgets(str,sizeof(str),stdin)!=NULL){
  // while(scanf("%[^/n]s",str)!=EOF){

    //strstrで探索
  if((strstr(str,"the")) || (strstr(str,"this")) || (strstr(str,"that"))){
    printf("%s",str);
    continue;
  }
  int len=strlen(str);
    for(int i=1;i<=26;i++){
      for(int j=0;j<len;j++){
	if(str[j]>='a' && str[j]<='z'){       
	  str[j]++;
	  if(str[j]=='{'){
	    str[j]='a';
	  }
	}
      }
      //strstrで探索
      if((strstr(str,"the")) || (strstr(str,"this")) || (strstr(str,"that")))break;
    }
    printf("%s",str);
  }
   return 0;
}

	