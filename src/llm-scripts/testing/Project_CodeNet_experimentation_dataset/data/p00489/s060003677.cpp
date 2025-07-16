#include <cstdio>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> P;
P po[100], res[100];
int main() {
    int n; scanf("%d",&n);
    for (int i=0; i<n; i++) {
        po[i].second=i;
        po[i].first=0;
    }
    for (int i=0; i<n*(n-1)/2; i++) {
        int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
        if (c>d) {
            po[a-1].first+=3;
        } else if (c<d) {
            po[b-1].first+=3;
        } else {
            po[a-1].first++;
            po[b-1].first++;
        }
    }
    sort(po, po+n);
    int pos=1, cnt=0, bef=0;
    for (int i=n-1; i>=0; i--) {
        if (bef!=po[i].first) {
            pos+=cnt;
            res[i].first=po[i].second;
            res[i].second=pos;
            cnt=1; bef=po[i].first;
        } else {
            res[i].first=po[i].second;
            res[i].second=pos;
            cnt++;
        }
    }
    sort(res,res+n);
    for (int i=0; i<n; i++) printf("%d\n",res[i].second);
}