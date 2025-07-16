#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int d=INT_MAX;
    for(int i=0;i<=s.size()-3;i++)
    {
        int k=i+2;
        int k1=0;
        for(int j=i;j<=k;j++)
        {
            k1=k1*10+(s[j]-'0');
        }
        int c=k1>753?(k1-753):753-k1;
        d=(c<d)?c:d;

    }
    cout<<d<<endl;
    return 0;
}
