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
        int n, q;
        cin >> n >> q;
        if(n == 0)
            return 0;

        vector<int> num(101);
        for(int i=0; i<n; ++i){
            int m;
            cin >> m;
            for(int j=0; j<m; ++j){
                int a;
                cin >> a;
                ++ num[a];
            }
        }

        int ret = 0;
        for(int i=1; i<=100; ++i){
            if(num[i] >= q && num[i] > num[ret])
                ret = i;
        }
        cout << ret << endl;
    }
}