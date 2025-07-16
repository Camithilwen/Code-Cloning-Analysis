#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    constexpr ll MOD = 1000000007;
    constexpr ll MAX = 1 << 20;

    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    //累積XOR
    vector<ll> b(N + 1, 0);
    for (ll i = 0; i < N; i++) {
        b[i + 1] = b[i] ^ A[i];
    }

    //今いるマスに好きな整数をXとしている場合に累積XORがXとして到達する場合の数
    vector<ll> dp(MAX, 1);

    //今いるマスに好きな整数をXとしている場合に累積XORがXとして到達する場合の数の累積和
    vector<ll> dp_sum(MAX, 0);

    //累積XORが0になった回数
    ll zero_num = 0;

    //前回累積XORがXとなったときのzero_numの値
    vector<ll> last_zero_num(MAX, 0);

    for (ll i = 1; i < N; i++) {
        //累積XORがb[i]としてここに到着する場合の数を次の2通りに分けて計算
        //1) 前にb[i]として届くパターンの最後だけをここに入れ替え
        //   つまり以前のdp[b[i]]そのものなので(2)を+=で足せば良い
        //2) b[i]として到達する累積和と前回以降から0が出てきた数との掛け算
        (dp[b[i]] += dp_sum[b[i]] * (zero_num - last_zero_num[b[i]])) %= MOD;

        //累積和を計算しておく
        (dp_sum[b[i]] += dp[b[i]]) %= MOD;

        //b[i]となったときの0の出現回数を記録しておき差分を取れるようにする
        last_zero_num[b[i]] = zero_num;
        
        //0の出現回数を記録
        if (b[i] == 0) {
            zero_num++;
        }
    }

    if (b[N]) {
        //b[N]として遷移した先のものが答え
        cout << (dp[b[N]] + dp_sum[b[N]] * (zero_num - last_zero_num[b[N]])) % MOD << endl;
    } else {
        //X = 0の場合:累積XORが0になるところで仕切りを入れるか入れないか2通り
        ll ans = 1;
        for (ll i = 0; i < zero_num; i++) {
            (ans *= 2) %= MOD;
        }

        //X != 0の場合:Xで遷移してくる累積和の和
        for (ll X = 1; X < MAX; X++) {
            (ans += dp_sum[X]) %= MOD;
        }

        cout << ans << endl;
    }
}