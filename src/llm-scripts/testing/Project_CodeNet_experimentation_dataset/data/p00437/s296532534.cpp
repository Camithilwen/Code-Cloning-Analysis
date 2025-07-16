#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    for(;;){
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        if(a == 0)
            return 0;

        vector<vector<int> > check(n, vector<int>(4));
        for(int i=0; i<n; ++i){
            for(int j=0; j<4; ++j)
                cin >> check[i][j];
        }

        vector<int> quality(a+b+c+1, 2);
        for(int i=0; i<n; ++i){
            if(check[i][3] == 1){
                quality[check[i][0]] = 1;
                quality[check[i][1]] = 1;
                quality[check[i][2]] = 1;
            }
        }
        for(int i=0; i<n; ++i){
            if(check[i][3] == 0){
                if(quality[check[i][0]] == 1 && quality[check[i][1]] == 1)
                    quality[check[i][2]] = 0;
                if(quality[check[i][1]] == 1 && quality[check[i][2]] == 1)
                    quality[check[i][0]] = 0;
                if(quality[check[i][2]] == 1 && quality[check[i][0]] == 1)
                    quality[check[i][1]] = 0;
            }
        }

        for(int i=1; i<=a+b+c; ++i)
            cout << quality[i] << endl;
    }
}