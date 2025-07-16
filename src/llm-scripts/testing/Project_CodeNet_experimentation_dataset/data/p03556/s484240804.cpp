#include<iostream>
//#include<CastingInterop.h>
#include<string>
#include<array>
#include<math.h>
#include<sstream>
using namespace std;

int main()
{

	int num1,num3;
	cin >> num1;
	
	
		num3 = sqrt(num1);
			if (num3 % 10 != 0)
			{
				
				num3 = sqrt(num1);
				cout << num3 * num3;

			}
			else
			{
				cout << num3 * num3;
			}
}