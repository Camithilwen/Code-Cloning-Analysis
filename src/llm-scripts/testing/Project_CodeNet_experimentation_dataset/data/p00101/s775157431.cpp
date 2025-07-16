#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define BUFSIZE 1024

char buf[BUFSIZE];
int main()
{
	int n = atoi(fgets(buf, BUFSIZE, stdin)); 
	while (n--) {
		fgets(buf, BUFSIZE, stdin);
		for (int i = 0; i < strlen(buf); ++i) {
			if (strncmp(buf + i, "Hoshino", 7) == 0)
				buf[i+6] = 'a';
		}
		printf(buf);
	}
	return 0;
}