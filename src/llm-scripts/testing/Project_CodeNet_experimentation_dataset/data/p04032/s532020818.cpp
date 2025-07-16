#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

string s;

int main()
{
	cin >> s;
	for (int i = 0; i < s.size() - 1; i ++ )
		if (s[i] == s[i + 1])
		{
			cout << i + 1 << ' ' << i + 2 << endl;
			return 0;
		}
	
	for (int i = 0; i < s.size() - 2; i ++ )
		if (s[i] == s[i + 2])
		{
			cout << i + 1 << ' ' << i + 3 << endl;
			return 0;
		}
	
	puts("-1 -1");
	return 0;
}