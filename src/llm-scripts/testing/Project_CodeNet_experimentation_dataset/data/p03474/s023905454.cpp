#include <stdio.h>
#include <string.h>
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	getchar();

	char str[a+b+1];
	scanf("%s", &str);
	int length = strlen(str);
	int flag = 0;

	
	for(int i=0; i<length; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			continue;		//kl ada yg bukan angka, di skip
		}
		else if ('0' > str[i] || str[i] > '9')
		{
			if (i==a) //kalo dia bukan angka tp ternyata di indeks ke a, di okin
			{
				flag = 1;
				continue;
			}
			else if(i !=a)
			{
				flag = 0;
				break;
			}
		}
	}
	
	flag ? printf("Yes\n") : printf("No\n");
	
	return 0;
}