#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char h[3]={" \n"};
int main()
{
int w[3],x;
for(int j=0;j<2;j++){
 memset(w,0,sizeof(w));
 for(int i=0;i<10;i++){
 scanf("%d",&x);
 if(x>w[0]){w[2]=w[1]; w[1]=w[0]; w[0]=x;}
 else if(x>w[1]) {w[2]=w[1]; w[1]=x;}
 else if(x>w[2]) w[2]=x;
 }
 printf("%d%c",w[0]+w[1]+w[2],h[j]);
}
}