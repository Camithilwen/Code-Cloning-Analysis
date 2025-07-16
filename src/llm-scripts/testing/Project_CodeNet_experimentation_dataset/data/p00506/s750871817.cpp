#include <iostream>
#include <vector>
#include <algorithm>

#define INPUT_FROM_FILE (0)
#if INPUT_FROM_FILE
#include <fstream>
#endif

int calc_gcd(int n, int m){
	if(n == m){ return n; }
	if(n > m){
		std::swap(n, m);
	}
	return calc_gcd(n, m - n);
}

int main(int argc, char **argv){
#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
#endif
	int n = 0;
	std::vector<int> vec;
	int gcd = 1;

#if INPUT_FROM_FILE
	ifs >> n;
#else
	std::cin >> n;
#endif
	vec.resize(n);
	for(int i = 0; i < n; i++){
#if INPUT_FROM_FILE
		ifs >> vec[i];
#else
		std::cin >> vec[i];
#endif
	}
	std::sort(vec.begin(), vec.end());

	gcd = calc_gcd(vec[0], vec[1]);

	std::cout << "1" << std::endl;
	for(int i = 2; i <= gcd; i++){
		if(gcd % i == 0){
			if(n == 3){
				if(vec[2] % i == 0){
					std::cout << i << std::endl;
				}
			}
			else{
				std::cout << i << std::endl;
			}
		}
	}
	return 0;
}
