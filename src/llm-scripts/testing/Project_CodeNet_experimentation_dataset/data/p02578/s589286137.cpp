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
	int N;
	cin >> N;
	
	int64_t sum = 0;
	int64_t a;
	cin >> a;
	for (int i = 1; i < N; ++i)
	{
		int64_t tmp;
		cin >> tmp;
		if (tmp < a)
		{
			sum += (a - tmp);
			tmp += (a - tmp);
		}
		a = tmp;
	}

	cout << sum << endl;

}

int main() {
//	while(1)
	func();
	return 0;
}
