#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
    int n;
    while(cin >> n && n) {

        vector<pair<double,string> > v;
        map<double,vector<string> > ma;
        rep(i,n) {
            string l;
            int p,a,b,c,d,e,f,s,m;
            cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;

            double sum = a + b + c + d + e;
            sum += (m-1) * (d + e);
            int num = f*s*m - p;

            v.push_back(make_pair(num/sum,l));
            ma[num/sum].push_back(l);
        }

        vector<string> ans;
        map<double,vector<string> >::iterator ite;
        for(ite = ma.begin();ite != ma.end();ite++) {
            sort(ite->second.begin(),ite->second.end(),greater<string>());
            rep(i,ite->second.size()) {
                ans.push_back(ite->second[i]);
                // cout << ite->first << " " << ite->second[i] << endl;
            }
        }

        reverse(ans.begin(),ans.end());
        rep(i,ans.size()) cout << ans[i] << endl;

        cout << "#" << endl;

    }

    return 0;
}