#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string str;
	
	cin >> n;
	cin.ignore();
	while (n > 0){
		getline(cin, str);
		int len = 0;
		while (1){
			len = str.find("Hoshino", len);
			if (len == -1)  break;
			str[len + 6] = 'a';
		}
		cout << str << endl;
		n--;
	}
	return (0);
}