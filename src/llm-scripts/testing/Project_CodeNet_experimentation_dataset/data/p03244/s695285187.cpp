#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> V(N);
    for(int i = 0; i < N; ++i) cin >> V[i];
    map<int, int> odd, even;
    for(int i = 0; i < N; ++i){
        if(i%2 == 0) even[V[i]]++;
        else odd[V[i]]++;
    }
    priority_queue<pair<int, int> > qOdd, qEven;
    qOdd.emplace(0,0); qEven.emplace(0,0);
    for(auto it : odd) qOdd.emplace(it.second, it.first);
    for(auto it : even) qEven.emplace(it.second, it.first);
    
    if(qOdd.top().second != qEven.top().second) {
        int ans = N - qOdd.top().first - qEven.top().first;
        cout << ans << '\n';
    } else {
        int a = qOdd.top().first;
        int b = qEven.top().first;
        qOdd.pop();
        qEven.pop();
        int c = qOdd.top().first;
        int d = qEven.top().first;
        int ans = min(N - a - d, N - b - c);
        cout << ans << '\n';
    }
    return 0;
}