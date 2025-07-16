// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ull  unsigned long long
typedef string str;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int INF = 1e9 + 5;
const int N = 2e5 + 123;
int main(){
    speed;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i = 1; i <= (d - b); ++i){
        cout << 'U';
    }
    for(int i = 1; i <= (c - a); ++i){
        cout << 'R';
    }
    for(int i = 1; i <= (d - b); ++i){
        cout << 'D';
    }
    for(int i = 1; i <= (c - a); ++i){
        cout << 'L';
    }
    cout << 'L';
    for(int i = 1; i <= (d - b) + 1; ++i){
        cout << 'U';
    }
    for(int i = 1; i <= (c - a) +1;++i){
        cout << 'R';
    }
    cout << 'D';
    cout << 'R';
    for(int i = 1; i <= (d - b) + 1; ++i){
        cout << 'D';
    }
    for(int i = 1; i <= (c - a) + 1; ++i){
        cout << 'L';
    }
    cout << 'U';
}