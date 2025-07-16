#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a = N % 10;
    int b = ((N-a) % 100) / 10;
    int c = ((N-b*10) % 1000) / 100;
    if (a == 7 | b == 7 | c == 7) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}
