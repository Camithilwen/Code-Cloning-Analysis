#include <bits/stdc++.h>
using namespace std;
#define ll long long
int l[200000] = {0};

int main() {
    int N;
    map<int, int> d;

    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &l[i]);
    }

    for(int i=0;i<N;i++) {
        auto itr = d.find(l[i]);
        if(itr != d.end()) {
            d[l[i]]++;
        }
        else {
            d[l[i]] = 1;
        }
    }

    int ans = 0;
    for(auto i=d.rbegin();i!=d.rend();i++) {
        while(i->second > 0) {
            int isFinished = 0;
            for(int j=0;j<32;j++) {
                int v = pow(2, j) - i->first;
                if (i->first < v) {
                    break;
                }
                if (d.find(v)!=d.end()) {
                    if ((v!=i->first && d[v]>=1) || (v==i->first && d[v]>=2)) {
                        i->second--;
                        d[v]--;
                        ans++;
                        isFinished = 1;
                        break;
                    }
                }
            }
            if(isFinished==0) {
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}