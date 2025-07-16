#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;






int main()
{
	string s,t;
	cin >> s;
	t = s;
	for (int i = 0; i < s.size(); i++) {
		t[i] = s[s.size() - i-1];
	}
	cout << t << endl;


}