#include <iostream>
using namespace std;

int type(string s){
	if(s == "HIT")return 0;
	if(s == "OUT")return 1;
	if(s == "HOMERUN")return 2;
}
int main(){
	int n;
	string s;
	cin >> n;
	
	while(n--){
		int outCount = 0;
		int base = 0;
		int result = 0;
		while(outCount < 3){
			cin >> s;
			switch(type(s)){
			case 0:
				base <<= 1;
				base++;
				break;
			case 1:
				outCount++;
				break;
			case 2:
				result += __builtin_popcount(base)+1;
				base = 0;
				break;
			}
			if(base & 8)result++;
			base &= 7; // 0b0111
		}
		cout << result << endl;
	}
}