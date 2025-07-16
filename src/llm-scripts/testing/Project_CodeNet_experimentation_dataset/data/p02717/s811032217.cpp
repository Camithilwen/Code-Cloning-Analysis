#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;
#define for0(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define forA(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define forD(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define deb(x) cout<< #x << "=" << x <<endl
#define all(a) a.begin(),a.end()
#define re(x) cin>>x
#define readarr(a,n) for0(i,n) cin>>a[i]
#define mod 1000000007
#define INF 1000000000000000003
#define ff first
#define ss second
#define pb push_back 
#define pob pop_back
#define mp make_pair
#define endl "\n"

typedef long long int            ll;
typedef vector<int>              vi;
typedef pair<int, int>           pi;
typedef unordered_map<int, int>  mii;
typedef unordered_map<char, int> mci;
typedef unordered_set<int>       usi;

int gcd(int a,int b) { if (a == 0) return b; return gcd(b%a, a);}
int max(int a,int b){if(a>b) return a; else return b;}
int min(int a,int b){if(a<b) return a; else return b;}  
bool isPrime(int N){ for(int i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}

void solve(){
	int x,y,z;
	re(x),re(y),re(z);
	swap(x,y);
	swap(x,z);
	cout<<x<<" "<<y<<" "<<z;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1; 
    // cin>>t;
    while(t--){
      solve();
    }
    return 0;
}