#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b) - 1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)

#define PB push_back
#define INF (1<<29)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define CLR(a) memset(a,0,sizeof(a))
const int dx[] = {-1,0,0,1},dy[] = {0,1,-1,0};

typedef long long int ll;

using namespace std;

int main(){
    vector<int> w(10);
    vector<int> k(10);
    REP(i,10){
	cin >> w[i];
    }
    REP(i,10){
	cin >> k[i];
    }
    sort(RALL(w));
    sort(RALL(k));
    printf("%d %d\n",w[0]+w[1]+w[2],k[0]+k[1]+k[2]);
    return 0;
}