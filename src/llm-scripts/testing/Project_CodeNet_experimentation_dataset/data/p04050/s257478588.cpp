#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
vector<int>a;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;


	scanf("%d %d",&x,&n);

if(n==1){
scanf("%d", &k);
printf("%d\n",k);
if(k==1){
printf("1\n1\n");
}
else{
printf("2\n1 %d\n",k-1);
}
return 0;
}

x=0;
y=0;
z=0;

	f(i, n){
		scanf("%d", &k);
if(k%2==1){
x++;
if(y>0)z=k;
else y=k;
}
else a.push_back(k);
	}


if(x>2){
printf("Impossible\n");
return 0;
}

else if(x>1){
printf("%d",y);
f(i,a.size())printf(" %d",a[i]);
printf(" %d\n",z);

if(z==1){
printf("%d\n",a.size()+1);

printf("%d",y+1);
f(i,a.size())printf(" %d",a[i]);
printf("\n");
}
else{
printf("%d\n",a.size()+2);

printf("%d",y+1);
f(i,a.size())printf(" %d",a[i]);
printf(" %d",z-1);
printf("\n");
}
}


else if(x>0){
printf("%d",y);
f(i,a.size())printf(" %d",a[i]);
printf("\n");

printf("%d\n",a.size()+1);

printf("%d",y+1);
f(i,a.size()-1)printf(" %d",a[i]);
printf(" %d\n",a[a.size()-1]-1);
}


else{
printf("%d",a[0]);
f(i,a.size()-1)printf(" %d",a[i+1]);
printf("\n");

printf("%d\n",a.size());

printf("%d",a[0]+1);
f(i,a.size()-2)printf(" %d",a[i+1]);
printf(" %d\n",a[a.size()-1]-1);
}

	return 0;
}