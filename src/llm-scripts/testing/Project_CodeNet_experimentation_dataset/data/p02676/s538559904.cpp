#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <iomanip>
#include <math.h>
#include <fstream>

using namespace std;

class pqComp
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
};

bool sorting(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie();
    cout.tie();
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");
    
    
    // int t;
    // cin >> t;
    // for (int qwe = 0; qwe < t; qwe++)
    // {
    //     cout << "Case #" << qwe + 1 << ": ";
    // }


    int k;
    string s;
    cin >> k >> s;
    if (s.size() <= k)
    {
        cout << s << '\n';
    }
    else
    {
        cout << s.substr(0, k) << "...\n";
    }


    return 0;
}
