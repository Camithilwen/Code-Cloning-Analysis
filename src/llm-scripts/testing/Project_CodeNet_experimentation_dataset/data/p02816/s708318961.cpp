#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,1,-1,1,-1,-1,0};
int dy[]={0,1,1,-1,-1,1,0,-1};



int main(){
    int n;cin >> n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> aa(3*n);
    for (int i = 0; i < n; i++) {
        aa[i] = b[i] ^ b[(i+1)%n];
        aa[i + n] = a[i] ^ a[(i+1)%n];
        aa[i + 2 * n]  = aa[i + n];
    }
    vector< int > prefix(aa.size());
    for(int i = 1, j = 0; i < aa.size(); i++) {
        if(i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        } else {
            int k = max(0, j + prefix[j] - i);
            while(i + k < aa.size() && aa[k] == aa[i + k]) ++k;
            prefix[i] = k;
            j = i;
        }
    }
    for (int i = n; i < 2 * n; i++) {
        if(prefix[i] >= n){
            int k = i - n;
            cout << k << " " << (a[k] ^ b[0]) << endl;
        }
    }
    return 0;
}
