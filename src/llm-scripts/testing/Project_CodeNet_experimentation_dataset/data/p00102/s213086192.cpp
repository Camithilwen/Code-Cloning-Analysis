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
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        vector<vector<int> > num(n+1, vector<int>(n+1, 0));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cin >> num[i][j];
                num[i][n] += num[i][j];
                num[n][j] += num[i][j];
                num[n][n] += num[i][j];
            }
        }

        for(int i=0; i<=n; ++i){
            for(int j=0; j<=n; ++j){
                cout << setw(5) << num[i][j];
            }
            cout << endl;
        }
    }
}