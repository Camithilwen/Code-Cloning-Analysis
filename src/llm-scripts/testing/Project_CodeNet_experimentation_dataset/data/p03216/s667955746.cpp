#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

typedef pair<int, char> P;
#define fs first
#define sc second

int main(){
    int N, Q;
    string s;
    cin >> N >> s >> Q;

    vector<ll> ans;
    for(int i = 0; i < Q; i++){
        int k;
        cin >> k;

        ll cntD = 0;
        ll cntM = 0;
        ll cntDM = 0;
        ll res = 0;
        deque<P> que;
        for(int j = 0; j < N; j++){
            //余分なものをpop
            while(true){
                if(que.size() == 0) break;
                else if(que.back().sc == 'D' && que.back().fs > j - k) break;
                else if(que.back().sc == 'M'){
                    //cout << "popM" << endl;
                    cntM--;
                    que.pop_back();
                }
                else if(que.back().sc == 'D' && que.back().fs <= j - k){
                    //cout << "popD" << endl;
                    cntD--;
                    cntDM -= cntM;
                    que.pop_back();
                }
            }

            if(s[j] == 'D'){
                //cout << "pushD" << endl;
                que.push_front(P(j, 'D'));
                cntD++;
            }

            else if(s[j] == 'M'){
                //cout << "pushM" << endl;
                que.push_front(P(j, 'M'));
                cntM++;
                cntDM += cntD;
            }

            else if(s[j] == 'C'){
                //cout << "pushC" << endl;
                res += cntDM;
            }

            //printf("j = %2d  cntD = %2d  cntM = %2d  cntDM = %2d\n", j, cntD, cntM, cntDM);
        }

        ans.push_back(res);
    }

    for(ll v : ans){
        cout << v << endl;
    }

    return 0;
}
