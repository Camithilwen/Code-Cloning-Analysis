#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    vector<int> ab(2);
    rep(i, 2) cin >> ab[i];
    cout << ab[0] * ab[1] << endl;
    return 0;
}