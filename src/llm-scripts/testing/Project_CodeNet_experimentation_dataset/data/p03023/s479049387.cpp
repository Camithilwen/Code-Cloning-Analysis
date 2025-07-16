#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main(){
	double n;
	cin >> n;
	cout << n*(180-(360/n)) << endl;
	return 0;
}
