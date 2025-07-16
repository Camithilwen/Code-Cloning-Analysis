#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define REP(i,e) for (int i = 0; i != int(e); i++)
#define FORIT(i, A) for (auto i : A)
#define ISEQ(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << endl
#define SZ(x) ((int)(x).size())

int compare(const std::string& buf, const std::string& str)
{
}

int main(int argc, char const *argv[])
{
	int n;
	std::string s;
	std::getline(std::cin, s);
	std::stringstream ss(s);
	ss >> n;
	REP(i, n)
	{
		std::getline(std::cin, s);
		int k = 0;
		int l = s.length();
		while(k+7 <= l)
		{
			if (s.substr(k, 7) == "Hoshino")
				s.at(k+6) = 'a';
			k++;
		}
		std::cout << s << std::endl;
	}
	return 0;
}