#include <stdio.h>
#include <string.h>
int main (){
	char d[14], e[14], f[14];
	scanf ("%s %s %s", &d, &e, &f);
		if ( d[strlen(d) - 1] == e[0] && e[strlen(e) - 1] == f[0]){
			puts ("YES\n");
		}else {
			puts ("NO\n");
		}
	return 0;
}