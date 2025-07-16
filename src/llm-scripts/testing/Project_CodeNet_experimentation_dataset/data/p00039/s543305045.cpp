#include <iostream>
#include <string>
#include <map>
#include <string.h>
using namespace std;
int main(){
  map<char,int> ch;//文字の数字辞書登録
  ch['I']=1;
  ch['V']=5;
  ch['X']=10;
  ch['L']=50;
  ch['C']=100;
  ch['D']=500;
  ch['M']=1000;
  
  int ans=0;
  int len=0;
  char s[1111];
  while(cin >> s){
    len=strlen(s);
    for(int i=0;i<len;i++){
      if(ch[s[i]]<ch[s[i+1]]){//もしも引き算をすべき場合だったら
	ans-=ch[s[i]];
      }else{
	ans+=ch[s[i]];
      }
    }
    cout << ans << endl;
    ans=0;
  }
}