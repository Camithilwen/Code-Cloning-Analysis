#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<double, string> p, pair<double, string> q) 
{
    return (p.first > q.first) || (p.first == q.first && p.second < q.second);
}


int main()
{
    int n;

    while (cin >> n) {
        if (!n)
            break;

        vector<pair<double, string> > crop;

        for (int i = 0; i < n; i++) {
            int p, a, b, c, d, e, f, s, m;
            string l;
            double income = 0.0;

            cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
            
            income = (double)(m * s * f - p) / ((a + b + c) + (d + e) * m);

            crop.push_back(pair<double, string>(income, l));
        }
        sort(crop.begin(), crop.end(), cmp);

        for (int i = 0; i < crop.size(); i++) 
            cout << crop[i].second << endl;
        cout << "#\n";
    }

    return 0;
}