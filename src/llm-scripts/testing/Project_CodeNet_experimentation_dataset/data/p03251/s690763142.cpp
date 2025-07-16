#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

class Stream{
public:
    Stream(){

    }
    //配列以外の入力を受け取る
    void read(){

    }
    template<typename First, typename... Rest>
    void read(First& first, Rest&... rest){
        cin >> first;
        read(rest...);
    }
    //配列を区切って出力する
    template<typename T>
    void write_vec(vector<T>& v, char divider){
        for(size_t i = 0; i < v.size(); i++){
            cout << v[i] << divider;
        }
    }
};

int main(){
    Stream io;
    
    int N, M, X, Y;
    io.read(N, M, X, Y);
    vector<int> x(N);
    vector<int> y(M);
    for(int i = 0; i < N; i++){
        io.read(x[i]);
    }
    for(int i = 0; i < M; i++){
        io.read(y[i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if(X < Y && x.back() < y.front() && X < y.front() && x.back() < Y) cout << "No War";
    else cout << "War";
    return 0;
}