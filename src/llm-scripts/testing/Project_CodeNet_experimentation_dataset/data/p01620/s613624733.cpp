#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int k[100];
	char s[101];
	while (n != 0) {
		for (int i = 0; i < n; i++) cin >> k[i];
		cin >> s;
		int j = 0;
		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] >= 'a') s[i] -= 6;
			s[i] -= k[j];
			if (s[i] < 'A') s[i] += 52;
			j++;
			if (j == n) j = 0;
		}
		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] > 'Z') s[i] += 6;
		}
		
		cout << s << endl;
	cin >> n;
	}
	return 0;
}
