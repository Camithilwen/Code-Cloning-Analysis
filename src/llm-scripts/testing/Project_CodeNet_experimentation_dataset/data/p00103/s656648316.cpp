#include <iostream>
#include <string>
using namespace std;
int main(){
  string ibe;
  int n;
  int score=0,out=0;
  int hit=0;
  cin >> n;
  for(int i=0;i<n;i++){
    while(1){
      if(out >= 3)break;
      cin >> ibe;
      if(ibe=="HIT"){
	hit++;
	if(hit==4){
	  score++;
	  hit--;
	}
      }
      else if(ibe=="HOMERUN"){
	score=hit+1+score;
	hit=0;
      }
      else if(ibe=="OUT"){
	out++;
      }
    }
    cout << score << endl;
    out=0;
    hit=0;
    score=0;
  }
}