#include<algorithm>
#include<cstdio>
#define s(A) std::sort(A,A+10);
main(){
int Z[20],p;
for(int i=0;i<20;i++)
scanf("%d",&p),Z[i]=p;
s(Z);
s(Z+10);
printf("%d %d\n",Z[7]+Z[8]+Z[9],Z[17]+Z[18]+Z[19]);
}