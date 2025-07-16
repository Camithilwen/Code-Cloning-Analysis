#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j;
	int n;
	int len;
	char str[1024];
	
	scanf("%d\n", &n);
	
	for (j = 0; j < n; j++){
		fgets(str, 1024, stdin);
		
		len = strlen(str);
		for (i = 0; i < len; i++){
			if (strncmp(&str[i], "Hoshino", 7) == 0){
				strncpy(&str[i], "Hoshina", 7);
			}
		}
		printf("%s", str);
	}
	
	return (0);
}