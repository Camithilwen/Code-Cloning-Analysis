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
    int n;
    cin >> n;
    cin.ignore();

    while(--n >= 0){
        string s;
        getline(cin, s);
        int i = 0;
        for(;;){
            i = s.find("Hoshino", i);
            if(i == string::npos)
                break;
            s.replace(i, 7, "Hoshina");
        }
        cout << s << endl;
    }
}