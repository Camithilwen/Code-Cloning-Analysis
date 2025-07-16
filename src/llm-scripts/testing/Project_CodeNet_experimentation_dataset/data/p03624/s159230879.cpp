#include <cstdio>

char S[101010];

int main()
{
	scanf("%s", S);

	bool app[26];
	for (int i = 0; i < 26; ++i) {
		app[i] = false;
	}
	for (int i = 0; S[i] != '\0'; ++i) {
		app[S[i] - 'a'] = true;
	}
	for (int i = 0; i < 26; ++i) {
		if (!app[i]) {
			printf("%c\n", (char)(i + 'a'));
			return 0;
		}
	}
	puts("None");
	return 0;
}
