#include <stdio.h>
int main()
{
   int n,m,b[1000],a[1000];
   int sum[1000]={0};
   scanf("%d %d",&n,&m);
   for(int i=0;i<=n-1;i++){
     scanf("%d",&a[i]);
   }
   for(int j=0;j<=m-1;j++){
     scanf("%d",&b[j]);
   }
   for(int j=0;j<=m-1;j++){
     for(int i=0;i<=n-1;i++){
        if(b[j]>=a[i]) {sum[i]=sum[i]+1;break;}
     }
   }
   int max=-1;
   for(int k=0;k<=n-1;k++){
      if(sum[k]>=max) max=sum[k];
   }
   for(int i=0;i<=n-1;i++){
     if(sum[i]==max) printf("%d\n",i+1);
   }
   return 0;
}