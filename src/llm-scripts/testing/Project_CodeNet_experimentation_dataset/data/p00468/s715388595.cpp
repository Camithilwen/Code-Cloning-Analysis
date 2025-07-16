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

        vector<vector<int> > edges(n);
        for(int i=0; i<m; ++i){
            int a, b;
            cin >> a >> b;
            edges[a-1].push_back(b-1);
            edges[b-1].push_back(a-1);
        }

        vector<bool> check(n, false);
        check[0] = true;
        for(int i=0; i<2; ++i){
            vector<bool> next = check;
            for(int j=0; j<n; ++j){
                if(check[j]){
                    for(unsigned k=0; k<edges[j].size(); ++k)
                        next[edges[j][k]] = true;
                }
            }
            check = next;
        }

        int ret = -1;
        for(int i=0; i<n; ++i){
            if(check[i])
                ++ ret;
        }
        cout << ret << endl;
    }
}