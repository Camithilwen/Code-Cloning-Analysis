#define _USE_MATH_DEFINES

#include <iostream>	//cin, cout
#include <vector>	//vector
#include <algorithm> //sort,min,max,count
#include <string>	//string,getline
#include <ios>		//fixed
#include <iomanip>	//setprecision
#include <utility> //swap
#include <cstdlib>	//abs(int)
#include <cmath>	//sqrt
#include <sstream>	//stringstream,getline
#include <cmath>	//ceil,M_PI
#include <numeric>	//gcd

using namespace std;

int main() {

	string S;
	cin >> S;

	switch (S[2]) {
	case 'N': if (S[0] == 'S') {
		cout << 7 << endl;
	}
			else {
		cout << 6 << endl;
	}
			break;
	case 'E': cout << 5 << endl; break;
	case 'D': cout << 4 << endl; break;
	case 'U': cout << 3 << endl; break;
	case 'I': cout << 2 << endl; break;
	case 'T': cout << 1 << endl; break;
	}

	return 0;

}