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
        char c;
        vector<int> len(10);
        for(int i=0; i<10; ++i){
            if(!(cin >> len[i] >> c))
                return 0;
        }
        int v1, v2;
        cin >> v1 >> c >> v2;

        int sumLen = accumulate(len.begin(), len.end(), 0);
        int tmp = 0;
        for(int i=0; i<10; ++i){
            tmp += len[i];
            if(sumLen * v1 <= tmp * (v1 + v2)){
                cout << (i+1) << endl;
                break;
            }
        }
    }
}