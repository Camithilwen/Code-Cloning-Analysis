#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ctime>
using namespace std;

const unsigned long long BASE = (unsigned long long)(1e9 + 7);

#define FROM_0(i, n) for(int i = 0; i < (n); i++)
#define FROM_S(i, s, e) for(int i = (s); i < (e); i++)
#define ITER_BEGIN_END(iter, vec) for(auto iter = vec.begin(); iter != vec.end(); iter++)

int priceA[100001], priceB[100001];

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    int minA = 200000, minB = 200000;
    FROM_0(i, a)
    {
        cin >> priceA[i];
        minA = min(minA, priceA[i]);
    }
    FROM_0(i, b)
    {
        cin >> priceB[i];
        minB = min(minB, priceB[i]);
    }
    int minPrice = minA + minB;
    FROM_0(i, m)
    {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        int price = priceA[x] + priceB[y] - c;
        minPrice = min(price, minPrice);
    }
    cout << minPrice << endl;

    return 0;
}
