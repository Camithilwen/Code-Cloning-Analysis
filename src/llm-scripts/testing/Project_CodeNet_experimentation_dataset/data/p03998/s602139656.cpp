#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e10
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    unordered_map<char, string>cards;
    cin >> cards['a']>> cards['b']>> cards['c'];

    unordered_map<char, int>ct;
    char curr = 'a';

    while (true){
        ct[curr]++;
        if(ct[curr] > cards[curr].size()){
            if(curr=='a') cout << 'A' << endl;
            else if (curr=='b') cout << 'B' << endl;
            else cout << 'C' << endl;
            return 0;
        }
        curr = cards[curr][ct[curr]-1];
    }


}
        