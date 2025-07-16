#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

bool compare(P a,P b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    //cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);

    int n;cin>>n;
    vector<int> perm(8);
    REP(i,8){
        perm[i] = i;
    }
    vector<P> xy(n);
    REP(i,n){
        int x,y; cin >> x >> y;
        xy[i] = P(x,y);
    }
    sort(ALL(xy),compare);
    do{ 
        vector<P> permutation(8);
        REP(i,8){
            permutation[i] = P(i,perm[i]);
        }
        bool flag1 = true;
        REP(i,n){
            if(!binary_search(ALL(permutation),xy[i], compare)) {
                flag1 = false; break;
            }
        }
        if(!flag1) continue;

        bool flag = true;
        REP(i,7){
            FOR(k,i+1,8){
                if(abs(k-i) == abs(perm[k]-perm[i])){
                    flag = false; break;
                }
            }
            if(!flag) break;
        }
        if(flag == true){
            REP(i,8){
                REP(k,8){
                    if(binary_search(ALL(permutation),P(i,k),compare)){
                        cout<<'Q';
                    }
                    else cout<<'.';
                }
                cout<<endl;
            }
            return 0;
        }
        

    }while(next_permutation(ALL(perm)));
}
