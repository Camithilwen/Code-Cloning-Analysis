#include<iostream>
#include<string>

using namespace std;

int main(){
	int n=0,ct=0, score=0, out=0,run=0;
	string x;
	cin >> n;
	while (1){
		int  score = 0, out = 0, run = 0;
		while (1){
			cin >> x;
			if (x == "OUT"){
				out++;
			}
			if (x == "HOMERUN"){
				score+=run;
				score++;
				run = 0;
			}
			if (x == "HIT"){
				run++;
			}
			if (run > 3){
				run--;
				score++;
			}
			if (out == 3){
				cout << score << endl;
				ct++;
				break;
			}
		}
		if (ct == n)break;
	}
	return 0;

}