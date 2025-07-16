//  main.cpp
//  ABC174F2
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Binary Indexed Tree (Fenwick Tree)
//    使い方 :    BIT<int>bit
//                BIT<int> bt(n + 1); BITを初期化して
//                 bt.add(x, 1); xに1を加算
//                bt.sum(x); 0～xの累積和
template<typename T> // T: type of cost
struct BIT {
private:vector<T> array;
    const int n;
public:BIT(int _n):array(_n+1,0),n(_n) {}
    // iまでの累積和
    T sum(int i) {
        T x = 0;
        while(i>0){
            x += array[i];
            i-=i&-i; // LSBからの減算
        }
        return x;
    }
    // iからjの区間和
    T sum(int i,int j){
        T ret_i=sum(i-1);
        T ret_j=sum(j);
        return ret_j-ret_i;
    }
    // i番目にxを追加
    void add(int i, T x) {
        while(i<=n) {
            array[i] += x;
            i+=i&-i; // LSBへの加算
        }
    }
};

int main(int argc, const char * argv[]) {
    int n, q;
    cin >> n >> q;
    vector<int>c(n + 1);
    vector<int>p(n + 1, -1); // -1で初期化しておく
    vector<int> st(n + 1,0);
    // st(s)=t  左がsで右がtの矢印
    // ２回目の登場以降ならiをtとして登録
    for (int i = 1; i <= n; i++) {
        cin >> c.at(i);
        if (p.at(c.at(i)) != -1) {
            st.at(p.at(c.at(i)))=i;
        }
            p.at(c.at(i)) = i;
    }
    /*rep(i,n){
        cout<<i<<" "<<st.at(i)<<endl;
    }*/
    // クエリを整理する
    // q(l)=(r,i) q(左端)=(右端、読み込みの順番)
    int l, r;
    vector<int>len(q);
    vector<vector<P>> query(n+1,vector<P>()); // lの値によってクエリを整理する
    rep(i, q) {
        cin >> l >> r;
        query.at(l).emplace_back(r,i);
        len.at(i)=r-l+1;
    }
    /*for(int i=n-1;i>=0;i--){
        for(auto& x:query.at(i)){
            cout<<i<<" "<<x.first<<" "<<x.second<<endl;
        }
    }*/
 // BITを使う
    vector<int> cnt(q);
    BIT<int> bt(n + 1); // BITを初期化
    for (int s = n; s >= 1; s--) {
        if (st.at(s) > 0) {
            bt.add(st.at(s), 1);
        }
        for(auto& x:query.at(s)){
            cnt.at(x.second)=bt.sum(x.first);
        }
    }
    rep(i, q) {
        cout << len.at(i)-cnt.at(i) << endl;
    }
    return 0;
}
