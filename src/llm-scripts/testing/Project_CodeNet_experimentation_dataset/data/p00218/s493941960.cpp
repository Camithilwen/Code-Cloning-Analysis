#include <iostream>
#include <stdio.h>

char judge(int, int, int);

int main() 
{
	int pm, pe, pj;
	int number;
	
	while (true) {
		std::cin >> number;
		
		if (number == 0) {
			break;
		}
		
		for (int i = 0; i < number; i++) {
			std::cin >> pm >> pe >> pj;
			std::cout << judge(pm, pe, pj) <<std::endl;
		}
	}
	return 0;
}

char judge(int pm, int pe, int pj) {
	int avarage = (pm + pe + pj) /3;
	
	if  (pm == 100 || pe == 100 || pj == 100) {
		return 'A';
	} else if ((pm + pe) / 2 >= 90 || avarage >= 80) {
		return 'A' ;
	} else if (avarage >= 70) {
		return 'B';
	} else if (avarage >= 50 && (pm >= 80 || pe >= 80)) {
		return 'B';
	} else {
		return 'C';
	}
}