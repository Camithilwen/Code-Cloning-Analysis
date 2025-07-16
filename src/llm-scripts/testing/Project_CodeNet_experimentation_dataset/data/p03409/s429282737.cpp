#include<bits/stdc++.h>

using namespace std;
using P = pair<int,int>;

#define rep(i,n) for(int i=0; i<(int)n; i++)

bool isBigger(P a, P b){
    // return a > b
    return (a.first > b.first) && (a.second > b.second);
}

int main(){
    int N;
    cin >> N;

    vector<P> A(N);
    vector<P> B(N);

    rep(i,N){
        cin >> A.at(i).first;
        cin >> A.at(i).second;
    }
    rep(i,N){
        cin >> B.at(i).first;
        cin >> B.at(i).second;
    }

    sort(A.begin(), A.end(), [](P left, P right)->bool{if(left.second == right.second)return left.first > right.first;
                                                        else return left.second > right.second;});
    sort(B.begin(), B.end(), [](P left, P right)->bool{if(left.first == right.first)return left.second < right.second;
                                                        else return left.first < right.first;});

    // cout << "A:" << endl;
    // for(P p : A)cout << p.first << " " << p.second << endl;

    // cout << "B:" << endl;
    // for(P p : B)cout << p.first << " " << p.second << endl;

    int res = 0;
    vector<bool> usedA(N,false);
    rep(i,N){
        P b = B.at(i);
        rep(j,N){
            if(usedA.at(j))continue;
            P a = A.at(j);
            if(isBigger(b,a)){
                // printf("make pair: a(%d, %d)\tb(%d, %d)\n", a.first, a.second, b.first, b.second);
                usedA.at(j) = true;
                res++;
                break;
            }
        }
    }

    cout << res << endl;
}