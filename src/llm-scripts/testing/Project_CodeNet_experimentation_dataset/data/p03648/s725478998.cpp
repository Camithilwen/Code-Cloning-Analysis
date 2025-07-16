#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long k;                                      //k=123 
    cin>>k;
    long a,b,c;
    a=k/50+50;     //要特别处理的数的大小           a=123/50+50 = 2+50=52
    b=k%50;       //要特别处理的数的个数            b=123%50=23
    c=a-b-1;      //正常相等的数值                  c=52-23-1=28
    int x[55]={0};
    int xx=0;
    cout<<50<<endl;
    for(int i=0;i<50;i++)
    {
        if(i<b)
        {
            if(i==0)
            cout<<a;
            else
            cout<<" "<<a;
            x[xx]=a;
        }
        else
        {
            if(i==0)
            cout<<c;
            else 
            cout<<" "<<c;
            x[xx]=c;
        }
        xx++; 
    }
    cout<<endl;
 /*   int mmax;
    int index=0;
    cout<<"变化之后"<<endl;
    int s=123;
    while(s--)
    {
    	mmax=-1;
    	for(int j=0;j<50;j++)
    	{
    		if(x[j]>mmax)
    		{
    			mmax=x[j];
    			index=j;
			}
		}
		for(int j=0;j<50;j++)
		{
			if(index==j)
			{
				x[index]-=50;
			}
			else
			{
				x[j]++;
			}
		}
	}
	for(int i=0;i<xx;i++)
	{
		cout<<x[i]<<" ";
	 } */
    return 0;
}//   23+28=51;23个2加上22个1 55，  27个51 （23次）
//27 
//23个52  第22次后 还剩一个52+22，前面的都 -50+21=23  之后的 +22 = 50
//第23次后   前23个都变成了 24， 后27个变成了 51
//第27次后    后27个51 变成了 51-50+26 =27  前23个 24+27=51 
//所以经过50次之后  前23个52变成了51 ，后27个28 变成了27 
//第100次后   前23个变成了50，后27个变成26
//第23次后   前23个变成了22，后27变成了49 
