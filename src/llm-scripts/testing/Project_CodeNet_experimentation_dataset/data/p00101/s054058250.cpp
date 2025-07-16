#include <iostream>
#include <string>
#include <stdio.h>

#define N 1000

using namespace std;

int main()
{
	int n;
	int s;
	string str;

	cin >> n;
	cin.ignore();

	for(int i = 0; i < n; i++)
	{
		getline(cin,str);

		for(s = 0; s < N; s++){

		if(str[s] == 'H' && str[s+1] =='o' && str[s+2] == 's' && str[s+3] == 'h' 
			&& str[s+4] == 'i' && str[s+5] == 'n' && str[s+6] == 'o' ){
				
				str[s] = 'H';
				str[s+1] = 'o';
				str[s+2] = 's';
				str[s+3] = 'h';
				str[s+4] = 'i';
				str[s+5] = 'n';
				str[s+6] = 'a';
			}

		}
		cout << str << endl;

	}
}