#include<iostream>
#include<string>
using namespace std;
int main(){
  int n;
  cin>>n;
  string event;
  getline(cin,event,'\n');
  int i=0,out,b,score;
  while(n>0){
    out = 0;
    b = 0;
    score=0;
    while(out<3){
      getline(cin,event,'\n');
      if(event=="HIT"){
	b*=2;
	b+=1;
	if(b>8){
	  b-=8;
	  score++;
	}
      }
      if(event=="HOMERUN"){
	while(b>0){
	  score+=b%2;
	  b/=2;
	}
	score++;
      }
      if(event=="OUT"){
	out++;
      }
    }
    cout<<score<<endl;
    n--;
  }
  return 0;
}