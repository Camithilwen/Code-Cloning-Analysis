#include <bits/stdc++.h>

#define loop(v, f, l) for(int v = (f), v##_ = (l); v < v##_; ++v)

using namespace std;

typedef long long int lint;
static inline int in(){ int x; scanf("%d", &x); return (x); }
static inline lint inl(){ lint x; scanf("%lld", &x); return (x); }

int main()
{
	int n;

	scanf("%d\n", &n);
	loop(i, 0, n)
	{
		string line;
		std::getline(cin, line);
		int pos = 0;

		while( (pos = line.find("Hoshino", pos)) != string::npos )
		{
			line.replace(pos, 7, "Hoshina");
		}
		cout << line << endl;
	}
	return (0);
}