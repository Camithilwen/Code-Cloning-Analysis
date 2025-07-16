#define _USE_MATH_DEFINES
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int l[10];
	int v1, v2;
	char c;
	int d;

	while(cin >> l[0]){
		d=l[0];
		for(int i=1;i<10;i++){
			cin >> c >> l[i];
			d+=l[i];
		}
		cin >> c >> v1 >> c >> v2;

		double t = (double)d/(v1+v2);
		d=0;
		//cout << t<<endl;
		for(int i=0;i<10;i++){
			d+=l[i];
			//cout << v1*t <<" "<<d<<endl;
			if(v1*t <= d){
				cout << i+1 <<endl;
				break;
			}
		}
	}
	return 0;
}