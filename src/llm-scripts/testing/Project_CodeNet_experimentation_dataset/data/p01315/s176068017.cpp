#include <iostream>

#include <vector>

#include <algorithm>

#include <set>

#include <queue>

#include <stack>

#include <string>

#include <map>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>



using namespace std;



int main(void){

    int n;

    while (cin >> n, n) {

        vector<pair<double, string> > list;

        for (int i = 0; i < n; i++) {

            string l;

            int p, a, b, c, d, e, f, s, m;

            cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;

            double cost = (-1.0)*(m*s*f-p)/((a+b+c)+m*(d+e));

            list.push_back(make_pair(cost, l));

        }

        sort(list.begin(), list.end());

        for (int i = 0; i < list.size(); i++) {

            cout << list[i].second << endl;

        }

        cout << "#" << endl;

    }



	return 0;

}