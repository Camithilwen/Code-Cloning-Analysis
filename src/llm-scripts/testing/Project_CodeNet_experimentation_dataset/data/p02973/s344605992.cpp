#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

deque<int> col;



int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    col.push_front(a[0]);
    for (int i = 1; i < n; i++){
        int idx = lower_bound(col.begin(), col.end(), a[i]) - col.begin();
        if(idx == 0){
            col.push_front(a[i]);
        }else{
            col[idx-1] = a[i];
        }
    }
    int ans = col.size();
    cout << ans << endl;
}