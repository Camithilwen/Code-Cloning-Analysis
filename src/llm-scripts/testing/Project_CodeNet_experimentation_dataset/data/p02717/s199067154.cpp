#include<cstdio>
void swap(int &x,int &y)
{
	int t=x;
	x=y;
	y=t;
	return ;
}
int main()
{
	int a,b,c;
	while(~scanf("%d %d %d",&a,&b,&c))
	{
		int t;
		swap(a,b);
		swap(a,c);
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
} 