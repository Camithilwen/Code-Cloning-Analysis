#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int n, i, j;
	ios::sync_with_stdio();
	string s;

	scanf("%d", &n); cin.get();
	for (i=0; i<n; i++) {
		getline(cin, s);
		
		for (j=0; j+6 < s.size(); j++) {
			if (s.substr(j, 7) == "Hoshino") s[j+6] = 'a';
		}
		
		cout << s << endl;
		
	}
	return 0;
}