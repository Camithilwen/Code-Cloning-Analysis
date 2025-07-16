#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	while (1) {
		int a;
		cin >> a;
		if (a == 0)break;
		for (int b = 0; b < a; b++) {
			int  c, d, e;
			cin >> c >> d >> e;
			if (c == 100 || d == 100 || e == 100)cout << "A" << endl;
			else if (c+d>179)cout << "A" << endl;
			else if(c+d+e>239)cout << "A" << endl;
			else if(c+d+e>209)cout << "B" << endl;
			else if((c+d+e>149)&&(c>79||d>79))cout << "B" << endl;
			else cout << "C" << endl;
		}
   }
}