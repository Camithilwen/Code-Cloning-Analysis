#include <iostream>
using namespace std;
int main(){
	int l[10], v[2], sl;
	char c;
	while(cin >> l[0]){
		sl = l[0];
		for(int i = 1; i < 10; i++){
			cin >> c >> l[i];
			sl += l[i];
		}
		cin >> c >> v[0] >> c >> v[1];
		for(int i = 0; i < 10; i++){
			l[i] *= v[0] + v[1];
		}
		sl *= v[0];

		for(int i = 0; i < 10; i++){
			sl -= l[i];
			if(sl <= 0){
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}