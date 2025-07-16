#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
const int INF = 100005;
const int MAX_N = 100005;

bool comp(P a, P b){
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int n;
int main(){
    cin >> n;
    vector<P> a,b;
    int x,y;
    rep(i,n){
        cin >> x >> y;
        a.push_back(make_pair(x,y));
    }

    rep(i,n){
        cin >> x >> y;
        b.push_back(make_pair(x,y));
    }

    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end(),comp);

    int count =0;
    

    rep(i,n){
        for(int j=0; j<b.size(); j++){
            if(a[i].first < b[j].first && a[i].second < b[j].second ){
                count ++;
                b.erase(b.begin()+j);
                break;
            }
        }
    }

    cout << count << endl;

}