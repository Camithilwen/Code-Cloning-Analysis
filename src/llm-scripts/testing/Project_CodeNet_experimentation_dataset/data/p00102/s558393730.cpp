#include <stack>
#include <queue>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    
    int n;
    while(cin >> n && n != 0)
    {
        int a[11][11];
        for(int i = 0;i < n;i++)
        {
            for(int j = 0; j<n;j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i<n;i++)
        {
            a[i][n] = 0;
            a[n][i] = 0;
            for(int j = 0;j < n;j++)
            {
                a[i][n] += a[i][j];
                a[n][i] += a[j][i];
            }
        }
        a[n][n] = 0;
        for(int i = 0;i<n;i++)
        {
            a[n][n] += a[i][n];
        }
        for(int i = 0; i< n+1;i++)
        {
            for(int j = 0; j<n+1;j++)
            {
                cout << setw(5) << right << a[i][j];
            }
            cout <<endl;
        }
    }
    return 0;
}