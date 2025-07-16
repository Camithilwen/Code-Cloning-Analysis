#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
while(1){
int sina[1000],n,m,sum=0;
scanf("%d%d",&n,&m);
if(n==0&&m==0)return 0;
for(int i=0;i<n;i++){
scanf("%d",&sina[i]);
sum+=sina[i];
}
sort(sina,sina+n);
for(int i=n-m;i>=0;i-=m){
sum-=sina[i];
}
printf("%d\n",sum);
}
}