#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int runner = 0, out = 0, score = 0;
		while(out < 3){
			string e;
			cin >> e;
			if(e == "HIT"){
				runner = (runner << 1) + 1;
				if(runner & 0xf8){ ++score; }
			}else if(e == "HOMERUN"){
				++score;
				if(runner & 0x01){ ++score; }
				if(runner & 0x02){ ++score; }
				if(runner & 0x04){ ++score; }
				runner = 0;
			}else if(e == "OUT"){
				++out;
			}
			runner &= 0x07;
		}
		cout << score << endl;
	}
	return 0;
}