#include <iostream>
using namespace std;

int main(void){
	int n;
	cin>>n;

	while(n--){
		int out = 0;
		int first=0,second=0,third=0,score=0;
		while(out < 3){
			string s;
			cin>>s;
			if(s == "HIT"){
				score += third;
				third = second;
				second = first;
				first = 1;
			}
			else if(s == "HOMERUN"){
				score += third + second + first + 1;
				third = second = first = 0;
			}
			else{
				out++;
			}
		}
		cout<<score<<endl;
	}

	return 0;
}