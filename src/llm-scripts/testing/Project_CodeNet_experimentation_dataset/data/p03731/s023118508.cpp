#include <iostream>

using namespace std;

int main()
{
	int result = 0;

	int numberOfPerson, turnOffDelay;
	cin >> numberOfPerson >> turnOffDelay;
	
	int lastSwitch = 0;
	for (int i = 0; i < numberOfPerson; i++) {
		int time;
		cin >> time;
		int delta = time - lastSwitch;
		result += delta < turnOffDelay ? delta : turnOffDelay;
		lastSwitch = time;
	}
	result += turnOffDelay;

	cout << result << endl;
	return 0;
}