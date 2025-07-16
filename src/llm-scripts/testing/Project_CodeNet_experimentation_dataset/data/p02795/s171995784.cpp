#include<stdio.h>
int main()
{
	int h,w,k,omen;
	scanf("%d %d %d",&h,&w,&k);
	if(h > w) omen = h;
	else omen = w;
	int count = 1;
	for(int i = omen;i<k;i += omen)
	{
		count++;
	}
	printf("%d\n",count);
	return 0;
}