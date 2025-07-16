#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,a;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        a=sqrt(i);
        if(i%a==0&&i/a==a)
        {
            cout<<i<<endl;
            return 0;
        }
    }

	return 0;
}