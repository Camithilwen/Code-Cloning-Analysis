#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[25];
    cin>>str;
    char rev[25];
    for(int i=0;i<strlen(str);i++)
        rev[i]=str[strlen(str)-i-1];
    rev[strlen(str)]='\0';
    cout<<rev<<endl;
}