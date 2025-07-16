#include<stdio.h>
#define DAY 3
int main(void) {
	int i;
	int rain_cnt=0;
	char weather[1000];
	scanf("%s", weather);
	if (weather[0] == 'R')rain_cnt++;
	for (i = 1; i < DAY; i++) {
		if (weather[i - 1] == 'R'&&weather[i]=='R')rain_cnt++;
		if (weather[i - 1] == 'S' && weather[i] == 'R')rain_cnt = 1;
	}
	printf("%d", rain_cnt);
	return 0;
}