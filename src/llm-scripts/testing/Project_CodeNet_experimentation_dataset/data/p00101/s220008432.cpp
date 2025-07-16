#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
	int n;
	cin >> n;
	char *ho = "Hoshino";
	rep(i,n+1) {
		char c, s[2010];
		rep(j, 2000) {
			scanf("%c", &c);
			if(c == '\n') {
				s[j] = '\0';
				break;
			} else {
				s[j] = c;
			}
		}
		for(int j = 0; s[j] != '\0'; ++j) {
			int f = 1;
			rep(k,7) {
				if(s[j + k] != ho[k]) {
					f = 0;
					break;
				}
			}
			if(f) s[j + 6] = 'a';
		}
		if(i != 0) {
			printf("%s",s);
			cout << endl;
		}
	}
	return 0;
}