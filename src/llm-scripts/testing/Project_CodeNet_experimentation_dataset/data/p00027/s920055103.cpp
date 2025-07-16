#include<iostream>
using namespace std;

int main(){
	int m, d, ans, month, i, total = 0;
	while(1){
		cin >> m >> d;
		if (m == 0) break;
		for(i = 1; i < m; i ++){
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
				total += 31;
			}
			else if(i == 2){
				total += 29;
			}
			else{
				total += 30;
			}
		}
		total += d;

		ans = total % 7;

		switch (ans){
		case 1:cout << "Thursday" << endl;
			break;
		case 2:cout << "Friday" << endl;
			break;
		case 3:cout << "Saturday" << endl;
			break;
		case 4:cout << "Sunday" << endl;
			break;
		case 5:cout << "Monday" << endl;
			break;
		case 6:cout << "Tuesday" << endl;
			break;
		case 0:cout << "Wednesday" << endl;
			break;
		}
		
		ans = 0, total = 0;
	}

	return 0;
}