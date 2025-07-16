#include <iostream>
#include<cmath>

using namespace std;

int main()
{
    int n,i;
    cin>>n;
    double res;
    for(i=n; i>=1; i--)
    {
        res=pow(i,0.5);
        if(abs(res-int(res))==0)
        {
            cout<<i;
            return 0;
        }
    }
}
