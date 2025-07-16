#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
using namespace std;



const long long INF2 = (((ll)1<<31)-1);

int main(int argc, char* argv[])
{
    int n,q;
    scanf("%d%d", &n, &q);
    
    vector<pair<int, pair<int, pair<int,int> > > > z(q);     // type, s, t, x;
    int i;
    int cnt=0;
    for(i=0; i<q; i++) {
        int type, s, t, x;
        scanf("%d", &type);
        if(type==0) {
            scanf("%d%d%d", &s, &t, &x);
            z[i]=make_pair(type, make_pair(s, make_pair(t,x)));
        }
        else {
            scanf("%d", &s);
            z[i]=make_pair(type, make_pair(s, make_pair(0,0)));
            cnt++;
        }
    }
    int ansnum=cnt;

    set<pair<int,int> > zz;    // val, ansid
    vector<int> ans(ansnum, INF2);
    cnt=ansnum-1;
    for(i=q-1; i>=0; i--) {
        if(z[i].first==0) {
            int s=z[i].second.first;
            int t=z[i].second.second.first;
            int x=z[i].second.second.second;
            auto it=zz.lower_bound(make_pair(s,-INF));
            auto itend=zz.lower_bound(make_pair(t+1,-INF));
            while(it!=itend) {
                ans[it->second]=x;
                auto itnext=it; itnext++;
                zz.erase(*it);
                it=itnext;
            }
        }
        else {
            zz.insert(make_pair(z[i].second.first, cnt));
            cnt--;
        }
    }
    for(i=0; i<ansnum; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

