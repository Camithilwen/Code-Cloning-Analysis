#include <iostream>

using namespace std;

int main()
{
	double l[10], sum, v1, v2;
	char c;

	while (1) {
		for (int i = 0; i < 10; i++) {
			cin >> l[i] >> c;
		}
		if (cin.eof())	break;

		cin >> v1 >> c >> v2;

		sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += l[i];
		}

		sum *= v1 / (v1 + v2);

		for (int i = 0; i < 10; i++) {
			sum -= (double)l[i];
			
			if (sum <= 0) {
				cout << i + 1 << endl;
				break;
			}
		}
	}

	return 0;
}