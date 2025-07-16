#include <cstdio>
#include <cstring>

int main() {
	char str[110];
	scanf("%s", str);
	str[strlen(str) - 8] = 0;
	puts(str);
	return 0;
}
