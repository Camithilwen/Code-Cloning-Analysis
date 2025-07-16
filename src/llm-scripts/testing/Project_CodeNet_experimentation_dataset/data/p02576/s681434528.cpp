#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <assert.h>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    int N, X, T;
    cin >> N >> X >> T;
    cout << (N+X-1)/X*T;
    
}