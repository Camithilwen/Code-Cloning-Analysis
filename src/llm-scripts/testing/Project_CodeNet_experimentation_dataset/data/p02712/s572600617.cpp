#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long c = N*(N+1)/2;
    long long j = N / 3;
    long long k = N / 5;
    long long l = N / 15;
    c = c - 3*j*(j+1)/2 - 5*k*(k+1)/2 + 15*l*(l+1)/2;
    cout << c;
}


