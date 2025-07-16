#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 100050
int n,a[N],b[N],mp[N][3],l[2];
void gun() {
	puts("No"); exit(0);
}
int main() {
	scanf("%d",&n);
	int i,x,y,z;
	for(x=0;x<3;x++) for(i=1;i<=n;i++) scanf("%d",&mp[i][x]);
	for(i=1;i<=n;i++) {
		x=mp[i][0], y=mp[i][1], z=mp[i][2];
		if(x+1==y&&y+1==z) {
			if(z%3) gun();	
			a[i]=z/3, b[i]=0;
		}else if(x-1==y&&y-1==z) {
			if(x%3) gun();
			a[i]=x/3, b[i]=1;
		}else gun();
		if((a[i]&1)!=(i&1)) gun();
		if(b[i]) l[i&1]^=1;
	}
	for(i=1;i<=n;i++) {
		while(a[i]!=i) {
			l[!(i&1)]^=1;
			swap(a[i],a[a[i]]);
		}
	}
	puts(l[0]||l[1]?"No":"Yes");
}
