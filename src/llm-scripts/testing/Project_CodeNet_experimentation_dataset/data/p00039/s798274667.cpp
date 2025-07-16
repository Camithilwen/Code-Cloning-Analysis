#include <iostream>
using namespace std;

int main()
{
	char rome[110];
  int	num, ara, nu;
	while(cin >> rome){
		num = ara = nu = 0;
		for(int i = 0; rome[i] != '\0'; i++){
			if (rome[i] == 'I') num = 1;
			else if (rome[i] == 'V') num = 5;
			else if (rome[i] == 'X') num = 10;
			else if (rome[i] == 'L') num = 50;
			else if (rome[i] == 'C') num = 100;
			else if (rome[i] == 'D') num = 500;
			else if (rome[i] == 'M') num = 1000;

			if (nu < num)	ara += num - nu - nu;
			else ara += num;
			nu = num;
		}
		cout << ara << endl;
	}
	return (0);
}