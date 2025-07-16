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
    
    string S;
    io.read(S);
    string ans = "AC";
    if(S[0] != 'A') ans = "WA";
    int c = 0;
    for(int i = 1; i < S.size(); i++){
        if(!(S[i] <= 'z' && S[i] >= 'a')){
            if(i <= S.size() - 2 && i >= 2){
                c++;
            }
            else ans = "WA";
        }
    }
    if(c != 1) ans = "WA";
    cout << ans;
    return 0;
}