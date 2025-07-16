#include<stdio.h>

int main()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	if (x>9 || x<1 || y>9 || y<1 || z>9 || z<1)
	{
		printf("Error!");
	}
	else if( x == y && y == z && x == z){
		printf("No");
	}
	else if (x == z || x == y || y == z){
		printf("Yes");
	}
	else if (x>y || z>x || y>z){
		printf("No");
	}	
}