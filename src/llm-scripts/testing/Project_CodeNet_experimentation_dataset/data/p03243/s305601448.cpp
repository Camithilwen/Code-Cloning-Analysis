#include <algorithm>

#include <bitset>

#include <tuple>

#include <cstdint>

#include <cstdio>

#include <cctype>

#include <assert.h>

#include <stdlib.h>

#include <stdio.h>

#include <cassert>

#include <cfloat>

#include <climits>

#include <cmath>

#include <complex>

#include <ctime>

#include <deque>

#include <fstream>

#include <functional>

#include <iomanip>

#include <iostream>

#include <iterator>

#include <list>

#include <limits>

#include <map>

#include <memory>

#include <queue>

#include <random>

#include <set>

#include <stack>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <utility>

#include <vector>

#include <math.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int hundred = N / 100;
	int ten = N / 10 % 10;
	int one = N % 100 % 10;
	if (hundred < ten) {
		cout << (hundred + 1) * 111 << endl;
	}
	else if (hundred >= ten && hundred >= one) {
		cout << hundred * 111 << endl;
	}
	else {
		cout << (hundred + 1) * 111 << endl;
	}
}
