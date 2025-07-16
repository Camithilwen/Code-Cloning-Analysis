#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(std::string &str, char delim) {
	std::vector<std::string> result;
	std::istringstream is(str);
	std::string buf;
	while (getline(is, buf, delim)) {
		result.push_back(buf);
	}
	return result;
}

bool inputDataSet(std::vector<int> *l, int *v1, int *v2) {
	std::string line;
	if (!getline(std::cin, line)) { return false; }
	std::vector<std::string> tokens = split(line, ',');
	if (tokens.size() != 12) { return false; }
	for (int i = 0; i < 10; ++i) {
		std::istringstream is(tokens[i]);
		if (!(is >> (*l)[i])) { return false; }
	}
	std::istringstream is1(tokens[10]), is2(tokens[11]);
	if (!((is1 >> *v1) && (is2 >> *v2))) { return false; }
	return true;
}

template <class Iterator>
int sum(Iterator first, Iterator last) {
	int sum = 0;
	for (; first != last; ++first) { sum += *first; }
	return sum;
}

int main() {
	std::vector<int> l(10);
	int v1, v2;
	while (inputDataSet(&l, &v1, &v2)) {
		const int x1 = 0, x2 = sum(l.begin(), l.end());
		v2 = -v2;
		if (v1 == v2) { continue; }	// ツ堕環妥篠堕ャツ度 0 ツづ按づァツ古ーツ債キツつオツづ按つ「
		const double x = static_cast<double>(x1) + static_cast<double>(-(x1 - x2) * v1) / static_cast<double>(v1 - v2);	// ツ渉ャツ青板つェツ静伉偲個づつウツづェツづゥツづ債「ツづゥ
		int n = 0, sum = 0;
		for (std::vector<int>::iterator it = l.begin(); it != l.end() && static_cast<double>(sum) < x; ++it) {
			sum += *it;
			++n;
		}
		std::cout << n << std::endl;
	}
	return 0;
}