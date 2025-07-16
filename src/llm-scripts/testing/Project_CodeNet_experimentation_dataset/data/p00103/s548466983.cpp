#include<iostream>
#include<string>
using namespace std;

int main(){
  int n,cou=0;
  string str;
  cin >> n;
  while(n>cou){
    int cou_out=0,ans=0,ining=0;
    while(cou_out < 3){
      cin >> str;
      if(str == "HIT"){
	ining++;
	if(ining == 4){
	  ans++;
	  ining--;
	}
      }
      else if(str == "OUT"){
	cou_out++;
      }
      else if(str == "HOMERUN"){
	ans += ining+1;
	ining = 0;
      }
    }
    cou++;
    cout << ans << endl;
  }
}