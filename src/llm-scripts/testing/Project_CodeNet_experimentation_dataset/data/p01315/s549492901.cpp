#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int n;
    cin >> n;
    if(n == 0) return true;
    vector<pair<double,string> > ls;
    for(int i=0;i<n;i++){
        string l;
        int p, a, b, c, d, e, f, s, m;
        cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
        int X = f*s*m - p, Y = a+b+c+(d+e)*m;
        ls.emplace_back(make_pair(double(-X)/Y,l));
    }
    sort(ls.begin(), ls.end());
    for(int i=0;i<n;i++){
        cout << ls[i].second << endl;
    }
    cout << '#' << endl;
    return false;
}

int main(){
    while(!solve());
    return 0;
}
