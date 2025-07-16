#include<iostream>
#include<cstdio>
#define eps 10e-9
using namespace std;
int main()
{
    int data[10],sum=0;
    int v1,v2;
    while(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&data[0],&data[1],&data[2],&data[3],&data[4],&data[5],&data[6],&data[7],&data[8],&data[9],&v1,&v2)!=EOF)
    {
        sum=data[0];
        for(int i = 1; i < 10; ++i)
        {
            sum+=data[i];
            data[i]=sum;
        }
        //cout<<"sum="<<data[9]<<endl;
        double t=data[9]/(double)(v1+v2);
        //printf("t=%.9lf\n",t);
        for(int i = 0; i < 10; ++i)
        {
            if(v1*t<(double)data[i]+eps)
            {
                cout<<i+1<<endl;
                break;
            }
        }
    }
  return 0;
}