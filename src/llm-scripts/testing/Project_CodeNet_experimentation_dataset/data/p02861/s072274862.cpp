#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
    int N;
    cin >> N;
    double D[N][N];
    vector<P> c(N);
    rep(i,N) {
	double x,y;
	cin >> x >> y;
	c[i] = make_pair(x,y);
    }
    rep(i,N) {
	rep(j,N) {
	    double x0 = c[i].first;
	    double y0 = c[i].second;
	    double x1 = c[j].first;
	    double y1 = c[j].second;
	    D[i][j] = sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
	}
    }

    vector<int> l(N);
    rep(i,N) l[i] = i;
    double sum = 0;
    double n = 0;
    
    do{
	n++;
	rep(i,N-1) {
	    sum += D[l[i]][l[i+1]];
	}
    }while(next_permutation(l.begin(),l.end()));

    double ans = sum/n;
    printf("%.12lf\n",ans);
    
    return 0;
}

