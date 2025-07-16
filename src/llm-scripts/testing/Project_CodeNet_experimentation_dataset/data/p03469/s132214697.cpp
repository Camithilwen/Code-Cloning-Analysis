#include <stdio.h>
int main (){
	char year[4],month[2],day[2];
	scanf ("%[^/]/ %[^/]/ %s",year,month,day);
	printf ("2018/01/%s",day);
}