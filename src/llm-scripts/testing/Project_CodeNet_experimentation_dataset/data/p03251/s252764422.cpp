#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , m , X , Y;
int x[MAXX];
int y[MAXX];

int main()
{
    _FastIO;
    int a , b;
    cin >> n >> m >> X >> Y;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        if(i) a = max(a , x[i]);
        else    a = x[0];
    }
    for(int i = 0; i < m; i++){
        cin >> y[i];
        if(i)   b = min(b , y[i]);
        else    b = y[0];
    }
    int tp = max(X + 1 , a + 1);
    int yp = min(Y , b);
    if(tp > yp){
        cout << "War" << endl;
        return 0;
    }
    cout << "No War" << endl;
    return 0;
}
