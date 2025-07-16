#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> P;
int k, a[100000], dist[100000];
vector<int> v[100000];
vector<P> w;
bool b[100000];
void cal(int x, int y){
    dist[x] = y;
    b[x] = false;
    w.push_back(P(y, x));
    for(int i=0;i<v[x].size();i++){
        cal(v[x][i], y+1);
    }
}
int hin(int x, int y){
    if(b[x])return 0;
    b[x] = true;
    if(x == 0 || (a[x] == 0 && y == k-1))return 0;
    if(y == k-1)return 1;
    return hin(a[x], y+1);
}
int main() {
    int n, ans = 0;
    cin >> n >> k >> a[0];
    if(--a[0] != 0)ans++;
    for(int i=1;i<n;i++){
        cin >> a[i];
        v[--a[i]].push_back(i);
    }
    cal(0, 0);
    sort(w.begin(), w.end(), greater<P>());
    for(int i=0;i<w.size();i++){
        int p = w[i].second;
        if(!b[p]){
            ans += hin(p, 0);
        }
    }
    cout << ans << endl;
	return 0;
}
