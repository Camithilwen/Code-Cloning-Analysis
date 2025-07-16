#include <iostream>

char detClass(int pm, int pe, int pj)
{
	
	int mean = pm + pe + pj;
	if((pm == 100) | (pe == 100) | (pj == 100)) {
		return 'A';
	} else if( (pm + pe) >= 180) {
		return 'A';
	} else if( mean >= 240) {
		return 'A';
	} else if( mean >= 210) {
		return 'B';
	} else if( (mean >= 150) && ((pm >= 80) | (pe >= 80))) {
		return 'B';
	} else {
		return 'C';
	}
}

int main()
{
	int n, pm, pe, pj = 0;
	
	while(true) {
		std::cin >> n;
		if(n == 0) {
			break;
		}
		for(int i = 0; i < n; i++) {
			std::cin >> pm >> pe >> pj;
			std::cout << detClass(pm,pe,pj) << std::endl;
		}
	}
	return 0;	
}