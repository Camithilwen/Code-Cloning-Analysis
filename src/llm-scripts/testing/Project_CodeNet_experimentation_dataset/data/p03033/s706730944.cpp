#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

bool compare_by_a(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
    if(get<0>(a) != get<0>(b)){
        return get<0>(a) > get<0>(b);
    }else{
        return get<1>(a) > get<1>(b);
    }
}
int main()
{
    cout << fixed << setprecision(15);
    ll N, Q;
    cin >> N >> Q;

    vector<tuple<ll, ll, ll> > A(N);

    REP(i ,N){
        ll s, t, x;

        cin >> s;
        cin >> t;
        cin >> x;

        get<0>(A[i]) = x;
        get<1>(A[i]) = s;
        get<2>(A[i]) = t;
    }

    vector<ll> D(Q);
    REP(i, Q){
        cin >> D[i];
    }

    // 1つ目のキーで降順順ソート
    sort(A.begin(), A.end(), compare_by_a);

    // for(ll i=0; i<N; i++){
    //     cout << get<0>(A[i]) << " " << get<1>(A[i]) << " " << get<2>(A[i]) << endl;
    // }
    vector<queue<ll>> plus(Q+1);
    vector<queue<ll>> minus(Q+1);

    REP(i, N){
        ll start = get<1>(A[i]) - get<0>(A[i]);
        ll end = get<2>(A[i]) - get<0>(A[i]);

        start = max(0LL, start);
        end = max(0LL, end);

        auto Iter1 = lower_bound(D.begin(), D.end(), start);
        ll s_id = Iter1 - D.begin();

        auto Iter2 = lower_bound(D.begin(), D.end(), end);
        ll t_id = Iter2 - D.begin();

        // cout << "s_id: " << s_id << "t_id: " << t_id << endl;

        plus[s_id].push(get<0>(A[i]));
        minus[t_id].push(get<0>(A[i]));
        // for(ll j=max(0LL,s_id); j<min(Q, t_id); j++){
        //     ans[j] = get<0>(A[i]);
        // }
    }

    // cout << 2 << endl;
    // cout << 2 << endl;
    // cout << 10 << endl;
    // cout << -1 << endl;
    // cout << 13<< endl;
    // cout << -1 << endl;
    multiset<ll> ans;

    REP(i, Q){
        // cout << i << " : " << ans.size() << endl;
        //　候補のものをすべて入れる。
        while (!(plus[i].empty())) {
            ans.insert(plus[i].front());
            plus[i].pop();
        }

        // cout << "plusの後： ";
        // for(auto itr = ans.begin(); itr != ans.end(); ++itr) {
        //     cout << *itr << " ";
        // }
        // cout << endl;

        //　候補が終わったものを削除
        while (!(minus[i].empty())) {
            ll temp = minus[i].front();
            auto itr = ans.find(temp);
            if(itr != ans.end()){
                ans.erase(ans.find(temp));
            }
            // cout << *itr << endl;
            minus[i].pop();
        }
        // cout << "minusの後： ";
        // for(auto itr = ans.begin(); itr != ans.end(); ++itr) {
        //     cout << *itr << " ";
        // }
        // cout << endl;

        // 候補がないなら-1を出力
        if(ans.empty()){
            cout << -1 << endl;
        }
        else{
            auto itr = ans.begin();
            cout << *itr << endl;
        }
    }

    return 0;
}