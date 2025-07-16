#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    int N;
    cin >> N;
    if (N % 10 == 7 ||
    (N/10) % 10 == 7 ||
    (N/100) % 10 == 7){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
    return 0;
}