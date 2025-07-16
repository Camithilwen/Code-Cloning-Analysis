#include<algorithm>
#include<cstdio>
#define s(A,B) std::sort(A,B);
int main(){
int W[10],K[10],p;
for(int i=0;i<20;i++)
scanf("%d",&p),(i<10)?W[i]=p:K[i-10]=p;
s(W,W+10);
s(K,K+10);
int Wp=W[7]+W[8]+W[9],Kp=K[7]+K[8]+K[9];
printf("%d %d\n",Wp,Kp);
}