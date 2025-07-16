#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	long long int a, total=0;
	cin >> a;
	for(int i=1; i<=a; i++)
	{
		if(i%3 !=0 && i%5 != 0)
		{
			total += i;
		}
	}
	cout << total;
}

