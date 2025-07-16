#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;


void func()
{
	int64_t N, ai = 0;;
	cin >> N;
	for (int64_t i = 1; i <= N; ++i)
	{
		if (i % 3 == 0 || i % 5 == 0)
			continue;
		ai += i;
	}
	cout << ai << endl;
}

int main() {

//	while (1)
		func();
	return 0;
}
