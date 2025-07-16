#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009
struct dice{
	int up;
	int down;
	int east;
	int west;
	int north;
	int south;
};
dice a, b;
dice d[100];
char s[101]="NNNNENWNNNNENWNNNNENWNNNNENWENNNNWWNNNNE";
int x;
dice  input(){
	dice c;
	scanf("%d", &x);
	c.up = x;
	scanf("%d", &x);
	c.south = x;
	scanf("%d", &x);
	c.east = x;
	scanf("%d", &x);
	c.west = x;
	scanf("%d", &x);
	c.north = x;
	scanf("%d", &x);
	c.down = x;
	return c;
}
void nr(){
			x = a.north;
			a.north = a.up;
			a.up = a.south;
			a.south = a.down;
			a.down = x;
			return;
}
void sr(){
			x = a.south;
			a.south = a.up;
			a.up = a.north;
			a.north = a.down;
			a.down = x;
			return;
}
void er(){
	x = a.east;
	a.east = a.up;
	a.up = a.west;
	a.west = a.down;
	a.down = x;
	return;
}
void wr(){
	x = a.west;
	a.west = a.up;
	a.up = a.east;
	a.east = a.down;
	a.down = x;
	return;
}
bool comp(){
	if (a.up == b.up&&a.north == b.north&&a.east == b.east&&a.down == b.down&&a.south == b.south&&a.west == b.west)return true;
	else return false;
}
int main(void){
	int n,m;
	scanf("%d", &m);
	f(i, m)d[i] = input();
	n = strlen(s);
	bool ans = false;
	for (int j = 0; j < m; j++){
		for (int k = j + 1; k < m; k++){
	a = d[j];
	b = d[k];
f(i, n){
		if (s[i] == 'N'){
			nr();
		}
		else if (s[i] == 'S'){
			sr();
		}
		else if (s[i] == 'E'){
			er();
		}
		else if (s[i] == 'W'){
			wr();
		}
		ans = comp();
		if (ans == true)break;
	}
if (ans == true)break;
		}
if (ans == true)break;
	}
		if(ans==true)printf("No\n");
		else printf("Yes\n");

	return 0;
}