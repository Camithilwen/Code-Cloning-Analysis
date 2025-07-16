#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
	int N;
	

	scanf("%d", &N);
	cin.get();
	while(--N, N>=0){
		char instr[1001];
		char *t;

		gets(instr);
		while( (t = strstr(instr, "Hoshino")) != NULL){
			t += 6;
			*t = 'a';
		}

		printf("%s\n", instr);
	}


	return 0;
}