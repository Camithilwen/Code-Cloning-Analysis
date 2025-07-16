#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    int n;

    while(cin >> n && n) {
        int a = 0,b = 0;
        rep(i,n) {
            int x,y;
            cin >> x >> y;

            if(x == y) {
                a += x;
                b += y;
            } else if(x > y) {
                a += (x+y);
            } else {
                b += (x+y);
            }
        }

        cout << a << " " << b << endl;
    }

    return 0;
}