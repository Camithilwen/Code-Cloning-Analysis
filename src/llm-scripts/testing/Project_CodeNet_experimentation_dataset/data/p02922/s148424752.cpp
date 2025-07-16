#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	int a, b,i=0;
	cin >> a >> b;
	while (1) {
		if (a * i - i + 1 >= b) {
			cout << i << endl;
			return 0;
		}
		i++;
	}

	return 0;
}


