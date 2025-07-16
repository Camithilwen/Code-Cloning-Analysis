#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,a[100005];
bool work(){
	int num1=0,num2=0;
	for(int i=1;i<=n;i++)
		if(a[i]>1){
			if(a[i]&1)
				num1++;
			else
				num2++;
		}
	if(!num1&&!num2)
		return false;
	if(num2&1)
		return true;
	if(num1>1||!num1)
		return false;
	for(int i=1;i<=n;i++)
		if(a[i]>1&&a[i]&1){
			a[i]--;
			break;
		}
	int d=a[1];
	for(int i=2;i<=n;i++)
		d=__gcd(d,a[i]);
	for(int i=1;i<=n;i++)
		a[i]/=d;
	return !work();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	puts(work()?"First":"Second");
	return 0;
}