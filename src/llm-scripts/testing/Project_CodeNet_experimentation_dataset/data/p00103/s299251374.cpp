#include <iostream>
#include <sstream>

using namespace std;

int main(){
	string result[3]={"HIT", "HOMERUN" , "OUT"};
	string eventlist;
	int inning,run;
	int count = 0;
	int score;
	while(cin >> inning){
		for(int i=0;i<inning;i++){
			run = 0; score = 0;
			for(count=0;count < 3;){
				cin >> eventlist;
//				cout << eventlist << endl;
				if(eventlist == result[0]){
					score += (run/4);
					run = (2 * run + 1) % 8;
//					cout << run << "H" << score << endl;
				}
				else if(eventlist == result[1]){
					for(int j = 0;j < 3;j++){
						score += run % 2;
						run = run /2;
					}
					run = 0;
					score++;
//					cout << " " << score << endl;
				}
				else{
					count++;
//					cout << "o" << count << endl;
				}
			}
			cout << score << endl;
		}
	}
}