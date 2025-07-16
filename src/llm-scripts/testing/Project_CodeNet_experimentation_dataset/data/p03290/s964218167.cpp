#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;

int main(){
    ll d, g;
    ll min = INF;
    cin >> d >> g;
    vector<ll> p(d);
    vector<ll> c(d);
    for(int i = 0; i < d; i++) {
        cin >> p.at(i) >> c.at(i);
    }
    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<d); ++bit)
    {
        int max_index = -1;
        ll score = 0, problem = 0;
        /* bit で表される集合の処理を書く */
        bitset<10> tmp(bit);
        /* bit で表される集合の処理を書く */
        for(int i = 0; i < d; i++){
            if(tmp.test(i)) {
                score += p.at(i) * (i+1) * 100 + c.at(i);
                problem += p.at(i);
            }
            else max_index = i;
        }

        if(problem > min) continue;
        if(score == 0){
            while(score < g) {
                problem++;
                score += (max_index + 1) * 100;
                if(problem > p.at(max_index)) {
                    problem = INF;
                    break;
                }
            }

        }
        else if(g > score && g - score < p.at(max_index) * 100 * (max_index+1)) {
            problem += (g - score) / (max_index+1) / 100;
        }
        else if(g > score) continue;
        
        if(problem < min) min = problem;
    }
    cout << min << endl;
}