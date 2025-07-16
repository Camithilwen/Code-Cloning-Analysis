#include <bits/stdc++.h>

using namespace std;

#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define LL long long
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {
    _for(i,0,(int)(v.size()-1)) os << v[i] << " ";
    os << v[v.size()-1];
    return os;
}

template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){
    for(typename set<T>::iterator it = v.begin();it != v.end();it++)
    os << *it <<" ";
    return os;
}

const int maxn = 1e6+5;
const int maxh = 1e3+3;
const int mod = 1e9+7;
int cnt = 0;

int A[maxh];
int B[maxh];
int N,M;

int mult(LL a,LL b){
    return (a*b)%mod;
}

int main()
{
    cin >> N >> M;
    _rep(i,1,N) cin >> A[i];
    A[N+1] = -1;
    _rep(i,1,M) cin >> B[i];
    B[M+1] = -1;

    LL ans = 1;
    int pa = 1,pb = 1;
    sort(A+1,A+N+1,greater<int>());
    sort(B+1,B+M+1,greater<int>());

    for(int i = M*N;i >= 1;i--){
        if(A[pa] == i && B[pb] == i){
            pa++;pb++;
        }
        else if(A[pa] == i){
            ans = mult(ans,pb-1);
            pa++;
        }
        else if(B[pb] == i){
            ans = mult(ans,pa-1);
            pb++;
        }
        else{
            LL used = M*N - i;
            LL rest = (pa-1)*(pb-1);
            //cout << pa <<" "<< pb << endl;
            if(rest - used <= 0){ans = 0;break;}
            ans = mult(ans,rest-used);
        }
    }

    cout << ans << endl;

    return 0;
}
