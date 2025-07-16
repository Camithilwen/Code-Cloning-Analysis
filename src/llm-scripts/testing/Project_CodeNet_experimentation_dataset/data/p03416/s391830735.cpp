#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

// 回文チェック関数

bool Pal(string a)
{
	int size = a.length();
	rep(i, size / 2) if (a[i] != a[size - i - 1]) return false;
	return true;
}

int main()
{
	int a, b, count = 0;
	cin >> a >> b;

	for (int i = a; i < b + 1; i++) if (Pal(to_string(i))) count++;

	cout << count << endl;
	return 0;
}