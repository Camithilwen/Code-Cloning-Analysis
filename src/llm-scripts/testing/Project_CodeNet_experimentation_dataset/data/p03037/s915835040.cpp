#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
 
int main()
{
    int n,m;
    cin >> n >> m;
    int max = 0,min = 1e9;
    vector<vector<int>> G(m,vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> G[i][j];
        }
        if (max < G[i][0])
        {
            max = G[i][0];
        }
        if (min > G[i][1])
        {
            min = G[i][1];
        }
    }
    if (max > min)
    {
        cout << "0" << endl;
    }else{
        cout << min-max+1 << endl;
    }
}