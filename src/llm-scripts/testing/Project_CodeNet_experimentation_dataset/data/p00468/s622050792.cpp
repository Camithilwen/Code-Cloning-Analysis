#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;

set<int> guest;
int n, m;
vector<int> people[501];
int main()
{
    while((cin >> n >> m) && n && m)
    {
        int a, b;
        int t;
        for(int i=0;i<m;i++)
        {
            cin >> a >> b;
            people[a].push_back(b);
            people[b].push_back(a);
        }
        for(int i=0;i<people[1].size();i++)
        {
            t = people[1][i];
            guest.insert(t);
            for(int j=0;j<people[t].size();j++) guest.insert(people[t][j]);
        }
        guest.insert(1);
        cout << guest.size()-1 << endl;
        guest.clear();
        for(int i=0;i<n;i++) people[i].clear();
    }
}