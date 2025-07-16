#include <iostream>
using namespace std;

int main()
{
	int date[13][32];
	for(int i = 1;i<=31;i++)date[1][i] = i;
	for(int i = 1;i<=28;i++)date[2][i] = i+3;
	for(int i = 1;i<=31;i++)date[3][i] = i+4;
	for(int i = 1;i<=31;i++)date[4][i] = i;
	for(int i = 1;i<=31;i++)date[5][i] = i+2;
	for(int i = 1;i<=31;i++)date[6][i] = i+5;
	for(int i = 1;i<=31;i++)date[7][i] = i;
	for(int i = 1;i<=31;i++)date[8][i] = i+3;
	for(int i = 1;i<=31;i++)date[9][i] = i+6;
	for(int i = 1;i<=31;i++)date[10][i] = i+1;
	for(int i = 1;i<=31;i++)date[11][i] = i+4;
	for(int i = 1;i<=31;i++)date[12][i] = i+6;
	
	int month,day;
	while(true)
	{
		cin >> month;
		cin >> day;
		if(month==0&&day==0)break;
		switch (date[month][day] % 7)
		{
			case 0:
			cout << "Wednesday" << endl;
			break;
			case 1:
			cout << "Thursday" << endl;
			break;
			case 2:
			cout << "Friday" << endl;
			break;
			case 3:
			cout << "Saturday" << endl;
			break;
			case 4:
			cout << "Sunday" << endl;
			break;
			case 5:
			cout << "Monday" << endl;
			break;
			case 6:
			cout << "Tuesday" << endl;
			break;
		}

	}

	return 0;
}