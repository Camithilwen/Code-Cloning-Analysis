#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  char S[3];
  int ans=0;
  for(int i=0;i<3;i++){
  	cin >>S[i];
  }
  bool p = S[0] =='R';
  bool q = S[1] =='R';
  bool r = S[2] =='R';
  if(p && q && r){
    ans = 3;
  }else if((p&&q) || (q&&r)){
    ans = 2;
  }else if(p || q || r){
    ans =1;
  }else{
    ans=0;
  }
    
  cout << ans;
  return 0;
	
}
  