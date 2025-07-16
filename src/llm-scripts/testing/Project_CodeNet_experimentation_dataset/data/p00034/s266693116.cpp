#include<iostream>
using namespace std;

int main(void){
	int l[10];
	char c;
	double ls, x1, t, v1, v2;
	while(1){
		ls = 0;
		for(int i = 0; i < 10; i++){
			cin >> l[i] >> c;
			ls += l[i];
		}
		cin >> v1 >> c >> v2;
		if(cin.eof())break;
		x1 = t = 0.0;
		for(int i = 0; i < 10; i++){
			x1 += l[i];
			t = x1 / v1;
			if(x1 + t * v2 >=ls){
				cout << ++i << endl;
				break;
			}
		}
	}
	return 0;
}