#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int a;

    cin>>a;
    a += (a*a) + (a*a*a);
    cout<<a;
    cout<<endl;
    return 0;
}