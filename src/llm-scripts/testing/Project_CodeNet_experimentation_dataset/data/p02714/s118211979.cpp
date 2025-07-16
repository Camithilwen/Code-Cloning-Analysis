#include<iostream>
#include<string>
using namespace std;
int main()
{
    char s[5000];
    long long n,i,j,k,total=0,red[5000]={0},green[5000]={0},blue[5000]={0},r=0,g=0,b=0,x,y;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]=='R')
        {
            r++;
            red[i]=red[i-1]+1;
            blue[i]=blue[i-1];
            green[i]=green[i-1];
        }
        else if(s[i]=='G')
        {
            g++;
            green[i]=green[i-1]+1;
            red[i]=red[i-1];
            blue[i]=blue[i-1];
        }
        else if(s[i]=='B')
        {
            b++;
            blue[i]=blue[i-1]+1;
            red[i]=red[i-1];
            green[i]=green[i-1];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {          
            if((s[i]=='R'&&s[j]=='G')||(s[i]=='G'&&s[j]=='R'))
            {
                x=b-blue[j];
                y=(j-i)+j;
                if(s[y]=='B'&&x>0&&y<=n)
                {
                    x--;
                }
                total+=x;
            }
            else if((s[i]=='R'&&s[j]=='B')||(s[i]=='B'&&s[j]=='R'))
            {
                x=g-green[j];
                y=(j-i)+j;
                if(s[y]=='G'&&x>0&&y<=n)
                {
                    x--;
                }
                total+=x;
            }
            else if((s[i]=='B'&&s[j]=='G')||(s[i]=='G'&&s[j]=='B'))
            {
                x=r-red[j];
                y=(j-i)+j;
                if(s[y]=='R'&&x>0&&y<=n)
                {
                    x--;
                }
                total+=x;
            }
        }
    }
    cout<<total<<endl;
    return 0;
}