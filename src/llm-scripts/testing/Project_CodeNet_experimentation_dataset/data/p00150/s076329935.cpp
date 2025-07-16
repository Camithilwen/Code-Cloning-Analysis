#include<iostream>
using namespace std;
bool isp[10000];
main()
{
    isp[0]=isp[1]=1;
    for(int i=2;i<=100;i++)
    {
        if(isp[i])continue;
        for(int j=i*i;j<=10000;j+=i)isp[j]=1;
    }
    int n;
    while(cin>>n,n)
    {
        while(isp[n]||isp[n-2])n--;
        cout<<n-2<<" "<<n<<endl;
    }
}
