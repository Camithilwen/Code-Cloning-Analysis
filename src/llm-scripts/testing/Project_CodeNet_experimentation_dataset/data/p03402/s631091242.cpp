#include<stdio.h>
int main()
{
	printf("100 100\n");
    int m,n;
    scanf("%d%d",&m,&n);
    /*
    .*.*.*
    ******
    *.*.*.
    ......
    */
    /*for(int i=0;i<50;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(m<n&&(m-n)%2==0)
            {
                m--;
                printf(".");
            }
            else printf("#");
        }
        printf("\n");
    }*/
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(m!=1&&i%2==0&&j%2==0)
            {
                m--;
                printf(".");
            }
            else printf("#");
        }
        printf("\n");
    }
	/*
    for(int i=50;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(m>n&&(m-n)%2==0)
            {
                n--;
                printf("#");
            }
            else printf(".");
        }
        printf("\n");
    }*/
    for(int i=50;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(n!=1&&i%2!=0&&j%2!=0)
            {
            	printf("#");
                n--;
            }
            else printf(".");
        }
        printf("\n");
    }
}