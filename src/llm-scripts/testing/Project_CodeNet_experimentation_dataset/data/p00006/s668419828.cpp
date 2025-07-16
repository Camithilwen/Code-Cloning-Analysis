#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int i,b;
char srt[100];
gets(srt);
b=strlen(srt);
for(i=b-1;i>=0;i--)
{
    printf("%c",srt[i]);
}
printf("\n");
}