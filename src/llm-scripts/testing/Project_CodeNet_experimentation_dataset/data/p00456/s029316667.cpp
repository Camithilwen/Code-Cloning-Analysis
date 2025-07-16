#include <iostream>
#include <algorithm>
#include <vector>

/*int main(int argc, char **argv)
{
	int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;
	std::cout << std::min(a, std::min(b, c)) + std::min(d, e) - 50 << std::endl;
	return 0;
}*/
/*int main()
{
	int l, a, b, c, d;
	std::cin >> l >> a >> b >> c >> d;
	int japa, math;
	japa = a / c;
	if(a % c != 0){
		japa++;
	}
	math = b / d;
	if(b % d != 0){
		math++;
	}
	std::cout << l - std::max(japa, math) << std::endl;
}*/
/*int main()
{
	bool sub[31];
	int input;
	for(int i = 0; i < 31; i++){
		sub[i] = false;
	}
	for(int i = 0; i < 28; i++){
		std::cin >> input;
		sub[input] = true;
	}
	for(int i = 1; i < 31; i++){
		if(!sub[i]) std::cout << i << std::endl;
	}
}*/
int main()
{
	std::vector<int> w, k;
	int input;
	for(int i = 0; i < 10; i++){
		std::cin >> input;
		w.push_back(input);
	}
	for(int i = 0; i < 10; i++){
		std::cin >> input;
		k.push_back(input);
	}
	std::sort(w.begin(),w.end(),std::greater<int>());
	std::sort(k.begin(),k.end(),std::greater<int>());
	std::cout << w[0] + w[1] + w[2] << " " << k[0] + k[1] + k[2] << std::endl;
}