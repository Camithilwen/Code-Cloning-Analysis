#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

vector<int> Eratosthenes(int N){
	vector<int> arr(N,1);
    vector<int> res;
	for(int i = 2; i < sqrt(N); i++){
		if(arr[i]){
			for(int j = 0; i * (j + 2) < N; j++){
				arr[i *(j + 2)] = 0;
			}
		}
	}

	for(int i = 1; i < N; i++){
		if(arr[i]){
            res.push_back(i);
		}
	}
    return res;
}

const ll INF = 1LL << 60;
 
ll N;
vector<ll> a;
int main() {
    cin >> N;
    a.resize(N + 1);
    rep(i, N) cin >> a[i + 1];
    vector<ll> ans(N + 1, -1);
    for (int i = N; i > 0; i--) {
        int loop_cnt = N / i;
        if (loop_cnt >= 2) {
            ll tmp = 0;
            for (int j = i + i; j <= N; j += i) {
                tmp += ans[j];
            }
            tmp = tmp % 2;
            ans[i] = tmp ^ a[i];
        } else {
            ans[i] = a[i];
        }
    }
    set<ll> st;
    for (int i = 1; i <= N; i++) {
        if (ans[i] == 1) {
            st.insert(i);
        };
    }
 
    cout << st.size() << endl;
 
    for (auto v : st) {
        cout << v << " ";
    }
    cout << "\n";
}