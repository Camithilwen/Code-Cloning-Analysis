#include <stdio.h>
int check(int a,int b,int c)
{
    //printf("[%d][%d][%d]\n",a,b,c);
    if(a != 14)return 0;
    else if(b == 23)return 1;
    else if(b == 1 && c == 10)return 1;
    else if(b == 19 && c == 19)return 1;
    else return 0;
}

int main()
{
    int longth,mem = 0;
    while(1)
    {
        char str[90] = {0};
        int mem1[90] = {0},mem2[90] = {0};
        if(scanf("%c",&str[0]) == -1)return 0;
        if(str[0] >= 'a' && 'z' >= str[0])mem1[0] = str[0] - 'a' + 1;
        for(int i = 1; i < 80; i++)
        {
            scanf("%c",&str[i]);
            if(str[i] == '\n')break;
            longth = i;
            if(str[i] >= 'a' && 'z' >= str[i])mem1[i] = str[i] - 'a' + 1;
        }
        for(int i = 0; i < longth; i++)
        {
            if(mem1[i] == 0);
            else if(mem1[i + 1] != 0)
            {
                if(mem1[i] <= mem1[i + 1])mem2[i] = mem1[i + 1] - mem1[i];
                else mem2[i] = 26 - mem1[i] + mem1[i + 1];
            }
        }
        /*for(int i = 0; i < longth; i++)
        {
            printf("[%d]",mem2[i]);
        }
        printf("\n");*/
        for(int i = 0; i < longth; i++)
        {
            if(mem2[i] != 0)/*printf("[%d]\n",i);*/if(check(mem2[i],mem2[i + 1],mem2[i + 2]))if(mem1[i] <= 20)mem = 20 - mem1[i];else mem = 26 - mem1[i] + 20;
            //else printf("no\n");
        }
        //printf("{{%d}}\n",mem);
        for(int i = 0; i < longth + 1; i++)
        {
            if(str[i] >= 'a' && 'z' >= str[i])printf("%c",(str[i] - 'a' + mem) % 26 + 'a');
            else printf("%c",str[i]);
        }
        printf("\n");
    }
}