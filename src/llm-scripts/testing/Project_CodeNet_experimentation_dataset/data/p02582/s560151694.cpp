#include <iostream>
using namespace std;

int main()
{
    string w;
    cin >> w;
    int c = 0;
    if (w == "RRR")
    {
        c = 3;
    }
    else if (w== "RRS" || w == "SRR")
    {
        c= 2;
    }
    else if (w == "SRS" || w == "RSR" || w == "SSR" || w == "RSS")
    {
        c = 1;
    }

    cout << c << endl;

    return 0;
}
