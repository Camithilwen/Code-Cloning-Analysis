#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main(){
    int N;
    int M;
    int Q;
    cin >> N >> M >> Q;
    int l;
    int r;
    vector<vector<int>> x(N, vector<int>(N, 0));
    vector<vector<int>> c(N, vector<int>(N, 0));
    vector<int> p(Q);
    vector<int> q(Q);
    int tmp_p;
    int tmp_q;
    for(int i=0; i<M; i++){
        cin >> l >> r;
        l--;
        r--;
        x[l][r]++;
    }
    for(int i=0; i<Q; i++){
        cin >> tmp_p >> tmp_q;
        tmp_p--;
        tmp_q--;
        p[i]=tmp_p;
        q[i]=tmp_q;
    }
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            c[i][j]+=x[i][j];
            if(j!=i){
                c[i][j]+=c[i][j-1];
            }
        }
    }

    for(int i=0; i<Q; i++){
        int ans=0;
        for(int j=p[i]; j<=q[i]; j++){
            ans+=c[j][q[i]];
        }
        cout << ans << endl;
    }

    return 0;
}
