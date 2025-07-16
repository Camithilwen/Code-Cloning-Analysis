////sfef
#include<stdio.h>
int main(){

int k,x,i,p,q,r;
scanf("%d %d",&k,&x);
p=(x-(k-1));
q=(x+(k-2));
r=(x+(k-1));
if(k==1)
{
    printf("%d",x);
}
else{
    for(i=p;i<=q;i++)    
    {
        printf("%d ",i);
    }
    printf("%d",r);
}

return 0;
}
