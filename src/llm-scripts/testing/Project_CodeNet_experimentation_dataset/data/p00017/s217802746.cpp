#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int key;

int dist(char s1,char s2){
 
  if(s1==s2){
    return 0;
  }else if(s1<s2){
    return s2-s1;
  }else{
    return 'z'-s1+s2-'a'+1;
  }
}

bool checkThe(char s[]){
  if(strlen(s)!=3){
    return false;
  }else{
    if(dist('t',s[0])==dist('h',s[1]) && dist('h',s[1])==dist('e',s[2])){
      key=dist('t',s[0]);
      return true;
    }
  }
  return false;
}
bool checkThis(char s[]){
  if(strlen(s)!=4){
    return false;
  }else{
    if(dist('t',s[0])==dist('h',s[1]) && dist('h',s[1])==dist('i',s[2]) && dist('i',s[2])==dist('s',s[3])){
      key=dist('t',s[0]);
      return true;
    }
  }
  return false;
}
bool checkThat(char s[]){
  if(strlen(s)!=4){
    return false;
  }else{
    if(dist('t',s[0])==dist('h',s[1]) && dist('h',s[1])==dist('a',s[2]) && dist('a',s[2])==dist('t',s[3])){
      key=dist('t',s[0]);
      return true;
    }
  }
  return false;

}
int main(){
 
  char str[100];
  char temp[100];
 
  char *tok;
  bool f;
  while(fgets(str,sizeof(str),stdin)!=NULL){
    key=0;
    f=false;
    for(int i=0;i<strlen(str);i++)
      temp[i]=str[i];
    temp[strlen(str)]='\0';

    str[strlen(str)]='\0';
    str[strlen(str)-1]='\0';
    tok=strtok(str," ");
 
    if(strlen(tok)==3){
      if(checkThe(tok)==true){
	f=true;
      }
    }else if(strlen(tok)==4){
      if(checkThat(tok)==true){
	f=true;
      }else if(checkThis(tok)==true){
	f=true;
      }
    }
    while(f==false && tok!=NULL){
      tok=strtok(NULL," ");
      if(tok!=NULL){
	if(strlen(tok)==3){
	  if(checkThe(tok)==true){
	    f=true;
	  }
	}else if(strlen(tok)==4){
	  if(checkThat(tok)==true){
	    f=true;
	  }else if(checkThis(tok)==true){
	    f=true;
	  }
	}
      }
    }
 
   
    for(int i=0;i<strlen(temp);i++){
      if('a'<=temp[i] && temp[i]<='z'){
	if(temp[i]-key>'z'){
	  printf("%c",(temp[i]-key));
	}else if(temp[i]-key<'a'){
	  printf("%c",(temp[i]-key)+26);
	}else{
	  printf("%c",(temp[i]-key));
	}
      }else{
	printf("%c",temp[i]);
      }
    }

  }

  return 0;
}