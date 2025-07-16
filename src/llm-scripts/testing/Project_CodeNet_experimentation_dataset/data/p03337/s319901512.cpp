#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int X = A*B;
    int Y = A+B;
    int Z = A-B;
    if((X>=Y)&&(X>=Z))
    {
        cout << X;

    }
    else if((Y>=X)&&(Y>=Z))
    {
        cout << Y;
    }
    else if((Z>=Y)&&(Z>=X))
    {
        cout << Z;
    }

    return 0;

}
