#include <iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int sum=0;
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='R')
        sum++;
        else
        sum=0;
        if(sum>count)
        count=sum;
    }
    cout<<count<<endl;
    return 0;
}
