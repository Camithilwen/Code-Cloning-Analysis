#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

bool barrier[2000][2000];
long long hist_barrier[2000][2001];
char S[2000][2001];

int main(){
    int H, W;
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> S[i];
    }
    for(int h = 0; h < H - 1; h++){
        for(int w = 0; w < W - 1; w++){
            int cnt_black = 0;
            for(int i = 0; i < 4; i++){
                cnt_black += (S[h + (i / 2)][w + (i % 2)] == '#') ? 1 : 0;
            }
            barrier[h][w] = (cnt_black % 2 == 1);
        }
    }
    for(int h = 0; h < H; h++){
        hist_barrier[h][0] = h + 1;
    }
    for(int w = 0; w < W; w++){
        hist_barrier[0][w] = 1;
    }
    for(int h = 1; h < H; h++){
        for(int w = 1; w < W; w++){
            if(barrier[h-1][w-1]){
                hist_barrier[h][w] = 1;
            }else{
                hist_barrier[h][w] = hist_barrier[h-1][w] + 1;
            }
        }
    }

    long long ans = 0;
    for(int h = 0; h < H; h++){
        stack<pair<long long, int> > st;
        for(int w = 0; w < W + 1; w++){
            if(st.empty()){
                st.push(make_pair(h + 1, w));
            }else if(st.top().first > hist_barrier[h][w]){
                int last_pos;
                while(!st.empty() && st.top().first >= hist_barrier[h][w]){
                    ans = max(ans, (w - st.top().second) * st.top().first);
                    last_pos = st.top().second;
                    st.pop();
                }
                st.push(make_pair(hist_barrier[h][w], last_pos));
            }
            if(st.top().first < h + 1){
                st.push(make_pair(h + 1, w));
            }
        }
    }
    cout << ans << endl;

            
}
