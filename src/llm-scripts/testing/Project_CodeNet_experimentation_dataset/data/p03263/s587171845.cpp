#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"Yes"<<endl
#define cno cout<<"No"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;

queue<pint> que;

int main(){

    int h,w; cin >> h >> w;
    Graph G(h,vi(w));
    rep(i,h){
        rep(j,w){
        int a; cin >>a;
        G.at(i).at(j) = a;
        }   
        if(i%2 == 0){
            rep(k,w){
                if(G.at(i).at(k)%2 == 1) que.push(make_pair(i,k));
            }
        }
        else{
            for(int k = w-1; k>=0; --k){
                if(G.at(i).at(k)%2 == 1) que.push(make_pair(i,k));
            }
        }
    }
    queue<pint> ans;
    while(que.size() > 1){
        int m = que.front().first;
        int n = que.front().second;
        que.pop();
        int mn = que.front().first;
        int nn = que.front().second;
        bool ok = false;
        ans.push(make_pair(m+1,n+1));
        for(int i = m; i < h; ++i){
            if(i%2 == 0){
                for(int j = n+1; j < w; ++j){
                    ans.push(make_pair(i+1,j+1));
                    if(i == mn && j == nn) ok = true;
                    else ans.push(make_pair(i+1,j+1));
                    if(ok) break;
                }
                n = w;
            }
            else{
                for(int j = n-1; j >= 0; --j){
                    ans.push(make_pair(i+1,j+1));
                    if(i == mn && j == nn) ok = true;
                    else ans.push(make_pair(i+1,j+1));
                    if(ok) break;
                }
                n = -1;
            }

            if(ok){
                que.pop();
                break;
            }
        }
    }
    cout << ans.size()/2 << endl;
    while(!ans.empty()){
        cout << ans.front().first sp ans.front().second << " ";
        ans.pop();
        cout << ans.front().first sp ans.front().second << endl;
        ans.pop();
    }
    return 0;
}
