#include <bits/stdc++.h>
using namespace std;

#define ct cout
#define in cin
#define el endl
#define rep(i, N) for (int i = 0; i < N; i++)
#define ol(N) cout << N << endl

int main()
{
	int s1[4], s2[2];

	rep(i, 4){
		in >> s1[i];
	}
	in >> s2[0] >> s2[1];

	sort (s1, s1 + 4);
	reverse(s1, s1 + 4);

	ol(s1[0] + s1[1] + s1[2] + max(s2[0], s2[1]));

	return (0);
}