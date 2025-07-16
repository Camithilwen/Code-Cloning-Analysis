#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <map>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    swap(x,y);
    swap(x,z);
    cout << x << " " << y << " " << z << endl;
}