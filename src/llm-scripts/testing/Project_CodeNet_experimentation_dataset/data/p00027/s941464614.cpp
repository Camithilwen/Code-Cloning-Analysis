#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;


int zeller(int y , int m , int d){
	if(m==1 || m==2) {m+=12; y-=1;}
	return(y + y/4 - y/100 + y/400 + ((13*m+8)/5) + d )%7;
}

int main(){
	int m , d , w=4 , fw;
	while (cin >> m >> d, m){
		switch(zeller(2004,m,d)){
			case 0:
			cout << "Sunday" << endl;
			break;
			case 1:
			cout << "Monday" << endl;
			break;
			case 2:
			cout << "Tuesday" << endl;
			break;
			case 3:
			cout << "Wednesday" << endl;
			break;
			case 4:
			cout << "Thursday" << endl;
			break;
			case 5:
			cout << "Friday" << endl;
			break;
			case 6:
			cout << "Saturday" << endl;
		}
	}
	return 0; 
}