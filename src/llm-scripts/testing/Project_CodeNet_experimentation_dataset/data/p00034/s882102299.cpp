#include<iostream>
using namespace std;

int main(void)
{
	int L[10];
	int V[2];
	char C[11];

	while(cin >> L[0] >> C[0])
	{
		for(int i=1; i<10; i++)
			cin >> L[i] >> C[i];
		cin >> V[0] >> C[10] >> V[1];

		int sum = 0;
		for(int i=0; i<10; i++)
			sum += L[i];

		double col_point = 0;
		col_point = ((double)sum)/((double)V[0]+V[1])*V[0];

		int ruikei = 0;
		for(int i=0; i<10; i++)
		{
			ruikei += L[i];
			if(col_point <= ruikei)
			{
				cout << (i+1) << endl;
				break;
			}
		}
	}
	return 0;
}