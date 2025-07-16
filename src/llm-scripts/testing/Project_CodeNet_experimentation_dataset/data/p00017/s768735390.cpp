#include <string>
#include <iostream>
using namespace std;

int main(){
	string angou;
	
	while (getline(cin, angou)){
		int a = angou.size();

		for (int i = 0; i < 26; i++)
		{
			for (int q = 0; q < a; q++){
				if (angou[q] == ' ' || angou[q] == '.') continue;

				if (angou[q] == 'z') angou[q] = 'a';
				else angou[q]++;
			}

			bool theExists = angou.find("the") != string::npos;
			bool thisExists = angou.find("this") != string::npos;
			bool thatExists = angou.find("that") != string::npos;
			if (theExists || thisExists || thatExists)
			{
				cout << angou << endl;
				continue;
			}
		}
	}

	return 0;
}
