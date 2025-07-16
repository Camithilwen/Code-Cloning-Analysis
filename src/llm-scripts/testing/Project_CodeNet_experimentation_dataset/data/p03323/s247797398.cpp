#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney,chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun


#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")

int ctoi(char c) {
	switch (c)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default:
		cout << "ERR_ctoi" << endl;
		return -1;
	}
}
//最大公約数
template<typename T>
constexpr T gcd(T a, T b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}

//最小公倍数
template<typename T>
constexpr T lcm(T a, T b)
{
	return a * b / gcd(a, b);
}
int main() {
	int a, b;
	cin >> a >> b;
	if (a <= 8 && b <= 8) {
		PRI("Yay!");
	}
	else PRI(":(");
	return 0;
}