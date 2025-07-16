/*solved by RAKIB JOY*/
#include<stdio.h>
#include<stdbool.h>
bool dislike[10];
int main()
{
    int n,k,a;
    scanf("%d%d",&n,&k);
    while(k--)
    {
        scanf("%d",&a);
        dislike[a]=true;

    }
    for(int i=n;;i++)
    {
       int maybe=i;
       bool ok=true;
       while(maybe)
       {
          int last_digit=maybe%10;
          if(dislike[last_digit])
          {
             ok=false;
             break;
          }
          maybe/=10;
       }
       if(ok)
       {
          printf("%d\n",i);
          return 0;
       }
    }
    return 0;

}
