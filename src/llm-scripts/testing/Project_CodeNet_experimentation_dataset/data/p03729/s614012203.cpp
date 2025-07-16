#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
	int num,i,j,x,y,z;
	
	char a[20],b[20],c[20];
	scanf("%s %s %s",a,b,c);
	
	x = strlen(a);
	y = strlen(b);
	z = strlen(c);
	
	if(a[x-1] == b[0] && b[y-1] == c[0]) cout << "YES";
	else cout << "NO";
	
	
	
}