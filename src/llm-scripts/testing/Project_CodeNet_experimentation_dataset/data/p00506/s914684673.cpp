#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <math.h>

//#define PI 3.141592653589

using namespace std;



int main()
{
	int n;
	long seisuu[3];
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> seisuu[i];
	sort(seisuu, seisuu+n);
	
	for (int i=1; i<=seisuu[0]; i++)
	{
		if (n == 2)
		{
			if (seisuu[0]%i==0 && seisuu[1]%i==0)
			{
				cout << i << endl;
			}
		} else {
			if (seisuu[0]%i==0 && seisuu[1]%i==0 && seisuu[2]%i==0)
			{
				cout << i << endl;
			}
		}
	}
	//for (int i=0; i<n; i++) cout << seisuu[i] << endl;
	
	return 0;
}