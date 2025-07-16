#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define mk make_pair
#define S second
#define F first
typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
const int MAX = 1e5+5;
char s[MAX];

int main(int argc, char ** argv) {
	scanf(" %s", s);
	int sz = strlen(s);
	rep(i, 0, sz) {
	    if(i >= 1 && s[i] == s[i-1]) printf("%d %d\n", i, i+1), exit(0);
	    if(i >= 2 && s[i] == s[i-2]) printf("%d %d\n", i-1, i+1), exit(0);
	}
	puts("-1 -1");
	return 0;
}
