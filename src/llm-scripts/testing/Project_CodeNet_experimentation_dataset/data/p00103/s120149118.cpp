#include <cstdio>
#include <string>
using namespace std;

int main(void)
{
	int n;

	scanf("%d", &n);
	while(n-- > 0){
		int base[3] = {0};
		int score = 0;
		char s[10];
		int out = 0;
		while(out < 3){
			scanf("%s", s);
			string str = s;
			if(str == "HIT"){
				if(base[2] == 1) score++;
				base[2] = base[1];
				base[1] = base[0];
				base[0] = 1;
			}
			else if(str == "HOMERUN"){
				score += base[0];
				score += base[1];
				score += base[2];
				score++;
				base[0] = base[1] = base[2] = 0;
			}
			else {
				out++;
			}
		}
		printf("%d\n", score);
	}
	
	return(0);
}