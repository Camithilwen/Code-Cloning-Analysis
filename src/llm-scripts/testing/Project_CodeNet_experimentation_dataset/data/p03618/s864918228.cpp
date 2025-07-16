#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

string A;

const int maxn = 100;
int freq[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> A;
    int n = A.length();
    for(int i = 0;i < n;i++){
        freq[A[i] - 'a']++;
    } 
    ll ans = 1;
    for(int i = 0;i < 26;i++){
        for(int j = i + 1;j < 26;j++){
            ans += 1LL * freq[i] * freq[j];
        }
    }
    cout << ans << endl;
    return 0;
}
