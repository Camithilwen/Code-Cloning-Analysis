#include <stdio.h>
#define N 200002

char s[N], x, y;
int p[N];

int main()
{	 
	int i, j, tp, l;
	
	s[0] = 0;
	scanf("%s", s + 1);
	for(i = 1, j = 0; s[i]; j = i++){
		p[i] = j;
	}
	p[i] = j, l = i - 1;
	for(i = 2; x = s[i]; i++){
		if(x == 'T'){
			if(s[tp = p[i]] == 'S'){
				l -= 2;
				p[i + 1] = p[tp];
			}
		}
	}
	printf("%d\n", l);
		
	return 0;
}