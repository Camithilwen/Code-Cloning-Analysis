#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int main()
{
    char line[50];
    cin.getline(line,50);
    char a,b,c,d;
    int count=0;
    for(int i=0;i<strlen(line);i++)
    {
        if(line[i]==' ')
        {
            if(count==0)
            {
            a=line[i-1];
            b=line[i+1];
            count=1;
            }
            else
            {
              c=line[i-1];
              d=line[i+1];
            }
        }
    }
    if(a==b && c==d)
    {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}

