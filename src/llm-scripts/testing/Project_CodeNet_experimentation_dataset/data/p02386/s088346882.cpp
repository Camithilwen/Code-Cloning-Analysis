//#define _USE_MATH_DEFINES	//M_PI
#include <iostream>			//std::cout, std::cin
//#include <string>			//std::string
#include <vector>			//std::vector
//#include <valarray>			//std::valarray	??°????????????????¬???????
//#include <algorithm>		//std::sort
//#include <time.h>			//localtime_s
//#include <cstdlib>			//abs
//#include <cmath>			//abs, pow, sqrt, sin, cos,
//#include <fstream>			//std::ifstream
//#include <iomanip>			//std::setprecision
//#include <random>			//std::random(C++11)

int main(void) {

	
	//test??¨
	//std::ifstream in("test.txt");
	//std::cin.rdbuf(in.rdbuf());

	//??\???
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> dice(n, std::vector<int>(6));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			std::cin >> dice[i][j];
		}
	}

	//??????
	bool flg = true;
	std::vector<int> dice1(6), dice2(6), temp1(6);
	for (int i = 0; i < n - 1; i++) {
		dice1 = dice[i];
		for (int j = i + 1; j < n; j++) {
			dice2 = dice[j];

			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					for (int z = 0; z < 4; z++) {
						if (std::equal(dice1.begin(), dice1.end(), dice2.begin())) {
							flg = 0;
							x = y = z = 4;
							i = j = n;
						}
						temp1[0] = dice1[3];
						temp1[1] = dice1[1];
						temp1[2] = dice1[0];
						temp1[3] = dice1[5];
						temp1[4] = dice1[4];
						temp1[5] = dice1[2];
						dice1 = temp1;
					}
					temp1[0] = dice1[1];
					temp1[1] = dice1[5];
					temp1[2] = dice1[2];
					temp1[3] = dice1[3];
					temp1[4] = dice1[0];
					temp1[5] = dice1[4];
					dice1 = temp1;
				}
				temp1[0] = dice1[0];
				temp1[1] = dice1[3];
				temp1[2] = dice1[1];
				temp1[3] = dice1[4];
				temp1[4] = dice1[2];
				temp1[5] = dice1[5];
				dice1 = temp1;
			}

		}
	}

	if (flg) {
		std::cout << "Yes" << std::endl;	
	}
	else {
		std::cout << "No" << std::endl;
	}

}