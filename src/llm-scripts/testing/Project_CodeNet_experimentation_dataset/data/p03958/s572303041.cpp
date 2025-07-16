#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    int K, T, s, ans;   cin >> K >> T;
    vector<int> v(T);
    s = 0;
    for(int i=0; i<T; i++){
        cin >> v[i];
        s += v[i];
    }
    ans = 0;
    for(int i=0; i<T; i++){
        if(v[i] >= (s+1)/2) ans += v[i] - (s - v[i]) - 1;
    }
    cout << ans;
}