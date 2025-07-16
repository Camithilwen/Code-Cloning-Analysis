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

string solve(string s)
{
    int n = s.size();
    for(;;){
        for(int i=0; i<n; ++i){
            if('a' <= s[i] && s[i] <= 'z'){
                if(s[i] == 'z')
                    s[i] = 'a';
                else
                    ++ s[i];
            }
        }
        istringstream iss(s);
        string s1;
        while(iss >> s1){
            if(s1 == "the" || s1 == "this" || s1 == "that")
                return s;
        }
    }
}

int main()
{
    for(;;){
        string s;
        getline(cin, s);
        if(s == "")
            return 0;

        cout << solve(s) << endl;
    }
}