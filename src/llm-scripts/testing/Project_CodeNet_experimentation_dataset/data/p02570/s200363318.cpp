#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
void func()
{
	double D,T,S;
	cin >> D>>T>>S;
	
	if(D/S <= T)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}

int main() {
//	while(1)
	func();
	return 0;
}
