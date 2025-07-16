#include <cstdio>
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
    string s;
    cin >> s;
    int n = s.size();

    int ret = 0;
    for(int i=0; i<n; ++i){
        int j = i;
        while(j < n && s[j] == 'O')
            ++ j;
        int m = j - i;

        if(i - m >= 0 && s.substr(i - m, m) == string(m, 'J')){
            if(s.substr(j, m) == string(m, 'I')){
                ret = max(ret, m);
            }
        }

        i = j;
    }

    cout << ret << endl;
    return 0;
}