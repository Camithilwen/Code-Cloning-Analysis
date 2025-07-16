#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N;
    cin >> N;
    string A,B,C;
    cin >> A >> B >> C;
    int ret = 0;
    for(int i = 0;i < N;i++) {
        if(A.at(i) == B.at(i) && B.at(i) == C.at(i)) {
            ret = ret;
        }
        else if(A.at(i) == B.at(i)) {
            ret++;
        }
        else if(B.at(i) == C.at(i)) {
            ret++;
        }
        else if(A.at(i) == C.at(i)) {
            ret++;
        }
        else {
            ret += 2;
        }
    }
    cout << ret << endl;
}