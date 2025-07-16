#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <complex>
#include <ctime>
#include <cstdlib>

using namespace std;

inline int to_int(string s) {int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string to_str(T x) {ostringstream sout; sout << x; return sout.str();}

typedef long long ll;

int main()
{
	string s;
	map<char, int> ex;
	ex['I'] = 1; ex['V'] = 5; ex['X'] = 10; ex['L'] = 50; 
	ex['C'] = 100; ex['D'] = 500; ex['M'] = 1000;
	
	while(cin >> s)
	{
		int sum = 0;
		for(int i = 0; i < s.size()-1; i++)
		{
			char now = s[i], next = s[i+1];

			if(ex[now] < ex[next])
			{
				sum -= ex[now];
			}
			else
			{
				sum += ex[now]; 
			}
		}
		sum += ex[s[s.size()-1]];
		cout << sum << endl;
	}
}