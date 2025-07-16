#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,b,azb,abb,amb;
    cin>>a>>b;
    azb=a*b;
    abb=a+b;
    amb=a-b;
    cout << fmax(fmax(azb,abb),amb);
}
