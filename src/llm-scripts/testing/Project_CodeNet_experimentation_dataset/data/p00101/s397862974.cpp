#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
	int n;
	char str[10000],c;
	char *t;

	scanf("%d\n", &n);

	for(int i = 0; i < n; i++){
		gets(str);

		while(t=strstr(str, "Hoshino"),t){
			t[6]  = 'a';
		}
		printf("%s\n", str);
	}
	return 0;
}