#include<iostream>

int main()
{
    int a = 0;
    int Calc=0;

    std::cin >> a;
 
    Calc=a+(a*a)+(a*a*a);

    std::cout << Calc;

    return 0;
}