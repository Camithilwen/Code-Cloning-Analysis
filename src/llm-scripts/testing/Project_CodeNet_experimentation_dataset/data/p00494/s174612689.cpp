#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string s;
char t[1000001];
int ans;

int main(){
	scanf("%s", t);
	s = t;

	for(int i=0; i<s.size(); i++){
		int J, O, I;
		if(s[i] == 'J'){
			J = 0;
			while(s[i] == 'J'){
				i++;
				J++;
			}
			if(s[i] == 'O'){
				O = 0;
				while(s[i] == 'O'){
					i++;
					O++;
				}
				if(s[i] == 'I'){
					I = 0;
					while(s[i] == 'I'){
						i++;
						I++;
					}
					if(O <= J && O <= I) ans = max(ans, O);
				}
			}
		i--;
		}
	}
	printf("%d\n", ans);
	return 0;
}