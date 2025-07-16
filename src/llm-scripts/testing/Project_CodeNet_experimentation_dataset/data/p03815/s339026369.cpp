#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int mx2[] = {1,0};
int my2[] = {0,1};

class CXYetAnotherDieGame {
public:
	void solve(istream& in, ostream& out) {
        ll x;
        in >> x;
        if(x <= 6) out << 1 << endl;
        else if(x % 11 > 6) out << (x / 11) * 2 + 2 << endl;
        else if(x % 11 <= 6 && x % 11 != 0) out << (x / 11) * 2 + 1 << endl;
        else if(x % 11 == 0) out << (x / 11) * 2 << endl;
	}
};

int main() {
	CXYetAnotherDieGame solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}