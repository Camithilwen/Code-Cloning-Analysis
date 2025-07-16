

/*
Writer: SPD_9X2
https://atcoder.jp/contests/arc081/tasks/arc081_d

長方形にできる必要十分条件は、
内側にある四つ角の周り全てに関して、周りにある黒が偶数個
→そのような条件を満たす四つ角グリッドを考えると最大長方形になる

幅1の長方形に関しては全て作れるので、ans初期値はmax(H,W)
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int (i)=(n);(i)<(m);(i)++)
#define rrep(i,n,m) for(int (i)=(n);(i)>(m);(i)--)
using ll = long long;
const ll mod = 1000000007;
const ll half = 500000004;

int LRIH(vector<int>& lis){

    vector<vector<int>> stk(0);

    int ans = 0;
    int N = lis.size();

    rep(i,0,N){

        if (stk.size() == 0){
            stk.push_back({lis[i],i});
        }else if (stk[stk.size()-1][0] < lis[i]){
            stk.push_back({lis[i],i});
        }else if (stk[stk.size()-1][0] > lis[i]){

            int lastpos = -1;

            while ( (stk.size()>0) && (stk[stk.size()-1][0] > lis[i])){

                int nh = stk[stk.size()-1][0];
                int np = stk[stk.size()-1][1];
                lastpos = np;
                stk.pop_back();

                ans = max(ans , (nh+1)*(i-np+1));
            }

            stk.push_back({lis[i] , lastpos});
        }
    }

    return ans;
}

int main(){

    int H,W;
    cin >> H >> W;

    vector<vector<char>> S(H,vector<char> (W));
    rep(i,0,H){
        rep(j,0,W){
            cin >> S[i][j];
        }
    }

    vector<vector<int>> lis(H-1,vector<int> (W-1,0));

    rep(i,0,H-1){
        rep(j,0,W-1){
            if (S[i][j] == '#') lis[i][j] += 1;
            if (S[i+1][j] == '#') lis[i][j] += 1;
            if (S[i][j+1] == '#') lis[i][j] += 1;
            if (S[i+1][j+1] == '#') lis[i][j] += 1;
            lis[i][j] %= 2;
        }
    }

    vector<vector<int>> hist(H-1,vector<int> (W,0));

    rep(i,0,H-1){
        rep(j,0,W-1){

            if (lis[i][j] == 0){
                if (i==0){
                    hist[i][j] = 1;
                }else{
                    hist[i][j] = hist[i-1][j] + 1;
                }
            }

        }
    }

    int ans = max(H,W);
    rep(i,0,H-1){
        ans = max(ans , LRIH(hist[i]));
    }

    cout << ans << endl;
}