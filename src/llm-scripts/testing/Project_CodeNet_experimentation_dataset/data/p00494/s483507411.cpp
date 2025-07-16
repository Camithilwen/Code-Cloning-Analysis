#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ans=0;
  for(int i=0;i<s.size();i++){
    if(s[i]!='J') continue;
    else{
      int now=i+1;
      int J=1,O=0,I=0;
      int flag1=1,flag2=0;
      while(s[now]=='J'){
	//cout<<now<<endl;
	J++;
	now++;
      }
      while(s[now]=='O' && flag1){
	//cout<<now<<endl;
	O++;
	now++;
	flag2=1;
      }
      if(J<O){
	i=now-1;
	continue;
      }
      while(s[now]=='I' && flag2){
	//cout<<now<<endl;
	I++;
	now++;
      }
      if(O>I){
	i=now-1;
	continue;
      }
      ans=max(ans,min(I,min(O,J)));
      // cout<<ans<<endl;
      i=now-1;
      //cout<<i<<endl;
      //cout<<s[i]<<endl;
    }
  }
  cout<<ans<<endl;
  return 0;
}
	  