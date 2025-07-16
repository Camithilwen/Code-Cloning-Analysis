#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  char str[1002],cmp[8]="Hoshino";
  scanf("%d%c",&n,&str[0]);
  for(int i=0;i<n;i++){
    gets(str);
    int cnt=0;
    int j=0;
    while(str[j]!='\0'){
      if(str[j]==cmp[cnt])cnt++;
      else cnt=0;
      if(str[j]==cmp[cnt])cnt++;
      if(cnt==7){str[j]='a';cnt=0;}
      j++;
    }
    puts(str);
  }
}