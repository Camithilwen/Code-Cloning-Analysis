#include <cstdio>
#include <cmath>
#define buf 10000
using namespace std;
int k=0;
int B[buf];
void Answer(int n);
int PrimeNumber(int n);

int main(void){
  int i,n;
  char str[buf];

  for(i=2;i<buf;i++)
    PrimeNumber(i);
  for( ;fgets(str,sizeof(str),stdin)!=NULL; ){
    sscanf(str,"%d",&n);
    if(n==0) break;
    Answer(n);
  }
  return 0;
}

void Answer(int n){
  int i,j;
  for(i=0;i<k;i++){
    if(B[i]>n)
        break;
  }
  for(j=i-1;j>=0;j--){
    if(B[j]-B[j-1]==2){
      printf("%d %d\n",B[j-1],B[j]);
      break;
    }
  }
}

int PrimeNumber(int n){
  int i,c;
  if(n==2){
    B[k]=n;
    k++; return 0;
  }
  if(n<2 || n%2==0)
    return 0;
  c=sqrt(n);
  for(i=3;i<=c;i+=2){
    if(n%i==0)
      return 0;
  }
  B[k]=n;
  k++; return 0;
}