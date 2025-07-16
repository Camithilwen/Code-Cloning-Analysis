#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
ll X[3];
int N;
set<vector<int>> states;

void initialize(vector<int> v, int nowsum, int index) {
    states.insert(v);
    if(index == 3) return;
    for(int now = 1; now < X[index] - nowsum; now++) {
        v.push_back(now);
        initialize(v, nowsum + now, index);
        v.pop_back();
    }
    v.push_back(X[index] - nowsum);
    initialize(v, 0, index + 1);
}

void print(vector<int> v) {
    for(int i = 0; i < v.size(); i++) cerr << v[i] << " ";
    cerr << endl;
}
map<vector<int>, int> mp;
vector<int> vecs[50000];
int NEXT[50000][12];
bool checker(vector<int> v) {
    int index = 0;
    int nowsum = 0;
    for(int i = 0; i < v.size(); i++) {
        nowsum += v[i];
        if(index == 3 || nowsum > X[index]) {
            return false;
        }
        if(nowsum == X[index]) {
            nowsum = 0;
            index++;
        }
    }
    return index == 3;
}

void validate(vector<int> &v) {
    int index = 0;
    int nowsum = 0;
    for(int i = 0; i < v.size(); i++) {
        nowsum += v[i];
        if(index == 3 || nowsum > X[index]) {
            v.erase(v.begin());
            validate(v);
            return;
        }
        if(nowsum == X[index]) {
            nowsum = 0;
            index++;
        }
    }
    return;
}

ll dpnext[50000];
ll dpprev[50000];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> X[0] >> X[1] >> X[2];
    initialize({}, 0, 0);
    int num = 0;
    for(auto itr = states.begin(); itr != states.end(); itr++) {
        num++;
        mp[*itr] = num;
        vecs[num] = *itr;
        //print(*itr);
    }
    for(int i = 1; i <= num; i++) {
        for(int val = 1; val <= 10; val++) {
            vector<int> v = vecs[i];
            v.push_back(val);
            validate(v);
            NEXT[i][val] = mp[v];
            if(checker(vecs[i])) NEXT[i][val] = i;
            /*
            cerr << "----" << endl;
            print(vecs[i]);
            cerr << val << endl;
            print(v);
            */
        }
    }
    //cerr << states.size() << endl;
    dpprev[1] = 1;
    while(N--) {
        for(int index = 0; index <= num; index++) dpnext[index] = 0;
        for(int before = 1; before <= num; before++) {
            for(int val = 1; val <= 10; val++) {
                dpnext[NEXT[before][val]] += dpprev[before];
                dpnext[NEXT[before][val]] %= mod;
            }
        }
        swap(dpnext, dpprev);
    }
    ll ans = 0;
    for(int index = 1; index <= num; index++) {
        if(checker(vecs[index])) {
            ans = (ans + dpprev[index]) % mod;
            /*
            if(dpprev[index] == 0) continue;
            print(vecs[index]);
            cerr << dpprev[index] << endl;
            */
        }
    }
    cout << ans << endl;
    return 0;
}
