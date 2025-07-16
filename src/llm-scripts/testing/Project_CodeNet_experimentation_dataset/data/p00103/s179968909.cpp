#include <iostream>
#include <string>

using namespace std;

int main(void){
  string str;
  int n;
  int i=0;
  int ocnt=0, bcnt=0;
  int score=0;
  cin >> n;
  while(i < n){
	cin >> str;
	if(str == "OUT"){
	  ocnt++;
	}else if(str == "HIT"){
	  if(bcnt < 3){
		bcnt++;
	  }else{
		score++;
	  }
	}else if(str == "HOMERUN"){
	  score += bcnt+1;
	  bcnt = 0;
	}
	if(ocnt == 3){
	  cout << score << endl;
	  ocnt = 0;
	  bcnt = 0;
	  score = 0;
	  i++;
	}
  }
}