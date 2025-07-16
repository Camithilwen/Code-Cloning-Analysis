#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N;
int A[200005],B[200005];
int C[200005],D[200005];

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];
    for(int i=0;i<N;++i)cin>>B[i];
    for(int i=0;i<N;++i){
        C[A[i]]++;
        D[B[i]]++;
    }
    int ma=0;
    for(int i=1;i<=N;++i){
        if(C[i]+D[i]>N){
            cout<<"No\n";
            return 0;
        }
        C[i]+=C[i-1];
        D[i]+=D[i-1];
        chmax(ma,C[i]-D[i-1]);
    }
    cout<<"Yes\n";
    for(int i=0;i<N;++i){
        cout<<B[(i-ma+N)%N];
        if(i!=N-1)cout<<" ";
    }
    cout<<"\n";
}