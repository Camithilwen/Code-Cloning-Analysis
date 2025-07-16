#include<iostream>
using namespace std;
typedef pair<char,int> P;
string str;
int len,size=0,cnt=1,ans=0;
P t[1000000];
int main(){
  cin>>str;
  str.push_back('-');
  len=str.size();
  for(int i=1;i<len;i++){
    if(str[i-1]==str[i]){
      cnt++;
    }else{
      t[size++]=P(str[i-1],cnt);
      cnt=1;
    }
  }

  for(int i=0;i+2<size;i++){
    if(t[i].first!='J')continue;
    if(t[i+1].first!='O')continue;
    if(t[i+2].first!='I')continue;
    if(t[i].second<t[i+1].second)continue;
    if(t[i+1].second>t[i+2].second)continue;
    ans=max(ans,t[i+1].second);
  }
  cout<<ans<<endl;
  return 0;
}