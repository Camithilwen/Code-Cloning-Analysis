#include <stdio.h>
#include <string.h>

int main() {
	char str1[12], str2[12], str3[12];
	
	scanf("%s%s%s", str1, str2, str3);
	
	int len1 = strlen(str1), len2 = strlen(str2), len3 = strlen(str3);
	if (str1[len1 - 1] == str2[0] && str2[len2 - 1] == str3[0]) {
			puts("YES");
		}
		else {
			puts("NO");
		}
		
	
	
	return 0;
}