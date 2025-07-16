#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1000000000;
#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define rep(i,n) REP(i, 0, n)
typedef pair<double, string> P;
const double EPS = 1.0e9;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    while(cin >> N && N){
        vector<P> L;
        vector<double> F(9);
        string s;
        rep(i, N){
            cin >> s;
            rep(j, 9) cin >> F[j];
            double time = F[1] + F[2] + F[3];
            double money = 0.0;
            rep(i, F[8]){
                time += F[4] + F[5];
                money += F[6] * F[7];
            }
            money -= F[0];
            L.push_back(P(money / time, s));
        }
        sort(L.begin(), L.end(), [](P a, P b){
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });
        for(P k : L) cout << k.second << endl;
        cout << "#" << endl;
    }
    return 0;
}