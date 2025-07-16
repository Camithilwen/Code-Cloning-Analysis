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
        int n, m;
        cin >> n >> m;
        if(n == 0)
            return 0;

        vector<int> p(n);
        for(int i=0; i<n; ++i)
            cin >> p[i];
        sort(p.rbegin(), p.rend());

        for(int i=m-1; i<n; i+=m)
            p[i] = 0;
        cout << accumulate(p.begin(), p.end(), 0) << endl;
    }
}