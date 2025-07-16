#include <cstdio>

int main()
{
    int a,b,c,sum;
    scanf("%d/%d/%d",&a,&b,&c);
    
    sum = a + 1;
    
    if(b < 10)
    {
        printf("%d/0%d",sum,b);
    }
    else
    {
        printf("%d/%d",sum,b);
    }
    
    
    if(c < 10)
    {
        printf("/0%d",c);
    }
    else 
    {
        printf("/%d",c);
    }
    
    
    

}

