//#include <bits/stdc++.h>
//#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>
#include<utility>
#include<functional>
#include<map>
#include<set>
#include<cctype>
#include<fstream>


#define FOR(i, a, b) for( int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for( int i=(a);i>=(b);i--)
#define LFOR(i, a, b) for( long long int i=(a);i<=(b);i++)
#define LRFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979
#define MAXI 7500000

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;

int dy[5] = { 0,0,1,-1,0 };
int dx[5] = { 1,-1,0,0,0 };


int main(void) {
	
	while (1) {
		int n;

		cin >> n;
		if (n == 0) {
			break;
		}

		vector<string> l(n);
		vector<int> p(n), a(n), b(n), c(n), d(n), e(n), f(n), s(n), m(n), time(n), money(n);
		vector<double>adv(n);
		vector< pair<double, string> > pa(n);

		

		FOR(i, 0, n - 1) {
			cin >> l[i] >> p[i] >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> f[i] >> s[i] >> m[i];
			int timetmp = 0;
			int moneytmp = 0;
			timetmp = a[i] + b[i] + c[i] + (d[i] + e[i])*m[i];
			moneytmp = f[i] * m[i] * s[i];
			moneytmp -= p[i];
			adv[i] = (double)moneytmp / (double)timetmp;
			pa[i].first = adv[i];
			pa[i].second = l[i];

			//cout << moneytmp << " " << timetmp << endl;
		}

		sort(pa.begin(), pa.end());

		double tmp;
		int first;
		int second;

		

		RFOR(i, n - 1, 0) {
			tmp = pa[i].first;
			first = i;
			second = i;
			RFOR(j, i-1, 0) {
				//cout << i << " " << j << " " << tmp << " " << pa[j].first << endl;
				if (tmp == pa[j].first) {
					if (j == 0) {
						second = 0;
						break;
					}
					continue;
				}
				else {
					second = j + 1;
					break;
				}
			}
			i = second;
			//cout << first << " " << second << endl;
			FOR(j, second, first) {
				cout << pa[j].second << endl;
			}

		}

		/*RFOR(i, n - 1, 0) {
			cout << pa[i].second << endl;
		}*/

		cout << "#" << endl;


	}



	
	

	return 0;
}
