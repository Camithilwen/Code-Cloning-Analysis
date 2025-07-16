#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

int extgcd(int a, int b, int &x, int &y){
    int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1;
        y = 0;
    }
    return d;
}

int gcd_multi(vec a){
    int x, y, g;
    g = a[0];
    FOR(i, 1, a.size()) g = extgcd(g, a[i], x, y);
    return g;
}

signed main(){

    int N; cin >> N;
    vec A(N); readvec(A);

    int odd = 0, oddi;
    REP(i, N){
        if(A[i] % 2 == 1){
            odd++;
            oddi = i;
        }
    }

    if((N - odd) % 2 == 1){
        cout << "First";
        return 0;
    }

    if(!(odd == 1 && A[oddi] > 1)){
        cout << "Second";
        return 0;
    }

    bool f = true;

    while(true){

        A[oddi]--;
        int g = gcd_multi(A);
        REP(i, N) A[i] /= g;

        odd = 0, oddi;
        REP(i, N){
            if(A[i] % 2 == 1){
                odd++;
                oddi = i;
            }
        }

        if((N - odd) % 2 == 1){
            f = !f;
            break;
        }

        if(!(odd == 1 && A[oddi] > 1)) break;

        f = !f;
    }

    if(f){
        cout << "First";
    }else{
        cout << "Second";
    }

    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}