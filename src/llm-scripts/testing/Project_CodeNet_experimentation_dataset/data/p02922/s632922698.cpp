#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_power_socket(void) {
	int a, b;
	cin >> a >> b;

	int sum = 1;
	int cnt = 0;
	while (sum < b) {
		sum += (a - 1);
		cnt++;
	}

	cout << cnt << endl;
}
int main()
{
    b_power_socket();

    return 0;
}
