#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;
 
template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}
 
ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}
 
ll RS(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RS(N, P/2, M);
        return t*t % M;
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N;
    cin >> N;
    if(N == 2) {
        cout << -1 << endl;
        return 0;
    }
    vector<vector<char>> three = {
        {'a','a','b'},
        {'b','.','b'},
        {'b','a','a'}
    };
    vector<vector<char>> four = {
        {'a','a','c','a'},
        {'b','b','c','a'},
        {'a','e','d','d'},
        {'a','e','c','c'},
    };
    vector<vector<char>> five = {
        {'a','a','b','b','c'},
        {'b','.','.','a','c'},
        {'b','.','.','a','b'},
        {'a','b','b','.','b'},
        {'a','c','c','a','a'},
    };
    vector<vector<char>> seven = {
        {'.','a','a','b','b','c','.'},
        {'d','d','.','.','.','c','e'},
        {'f','.','.','.','a','.','e'},
        {'f','.','.','.','a','.','f'},
        {'h','.','a','a','.','.','f'},
        {'h','g','.','.','.','a','a'},
        {'.','g','a','a','b','b','.'},
    };
    if(N == 3) {
        for(int i = 0;i < 3;i++) {
            for(int j = 0;j < 3;j++) {
                cout << three.at(i).at(j);
            }
            cout << endl;
        }
        return 0;
    }
    else if(N == 6) {
        vector<vector<char>> ret(N,vector<char>(N,'.'));
        for(int i = 0;i < 2;i++) {
            for(int j = 0;j < 3;j++) {
                for(int k = 0;k < 3;k++) {
                    ret.at(3 * i + j).at(3 * i + k) = three.at(j).at(k);
                }
            }
        }
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                cout << ret.at(i).at(j);
            }
            cout << endl;
        }
        return 0;
    }
    int Four = 0;
    int Five = 0;
    int Seven = 0;
    for(int i = 0;i <= 400;i++) {
        for(int j = 0;j <= 400;j++) {
            for(int k = 0;k <= 400;k++) {
                if(i * 4 + j * 5 + k * 7 == N) {
                    Four = i;
                    Five = j;
                    Seven = k;
                    break;
                }
            }
        }
    }
    vector<vector<char>> ret(N,vector<char>(N,'.'));
    int cnt = 0;
    for(int i = 0;i < Four;i++) {
        for(int j = 0;j < 4;j++) {
            for(int k = 0;k < 4;k++) {
                ret.at(cnt + j).at(cnt + k) = four.at(j).at(k);
            }
        }
        cnt += 4;
    }
    for(int i = 0;i < Five;i++) {
        for(int j = 0;j < 5;j++) {
            for(int k = 0;k < 5;k++) {
                ret.at(cnt + j).at(cnt + k) = five.at(j).at(k);
            }
        }
        cnt += 5;
    }
    for(int i = 0;i < Seven;i++) {
        for(int j = 0;j < 7;j++) {
            for(int k = 0;k < 7;k++) {
                ret.at(cnt + j).at(cnt + k) = seven.at(j).at(k);
            }
        }
        cnt += 7;
    }
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            cout << ret.at(i).at(j);
        }
        cout << endl;
    }
}