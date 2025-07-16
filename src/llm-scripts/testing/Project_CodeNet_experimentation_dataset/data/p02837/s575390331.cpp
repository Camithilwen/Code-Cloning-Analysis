#include<iostream>
#include<vector>
#include<map>
#include<numeric>
using namespace std;

int mypow(int x, int y);
vector<int> my_bit(int n, int keta);


int main(){
    map<int, vector<pair<int, int>>> shogen;
    int N, A, x, y, n, sum_;
    int ans = 0;
    pair<int, int> p;

    //インプット
    std::cin >> N;
    vector<int> pattern(N);

    for(int i = 0; i < N; i++){
        //この時点で人名は-1されていく
        std::cin >> A;
        shogen[i] = {};

        for(int j = 0; j < A; j++){
            std::cin >> x >> y;
            p = std::make_pair(x - 1, y);

            if(shogen.count(i)){
                shogen[i].push_back(p);
            }
        }
    }
    //インプット終了


    // std::cout << N;

    std::map<int, vector<pair<int, int>>>::iterator iter;
    // std::cout << shogen.size() << "\n";
    // for(int i = 0 ; shogen.size(); i++){
    //     std::cout << iter->first << "\n";
    //     for(int j = 0; j < iter->second.size(); j++){
    //         std::cout << iter->second[j].first << " " << iter->second[j].first << "\n";
    //     }
    //     iter++;
    // }

    for(int i = 0; i < mypow(2, N); i++){
        pattern = my_bit(i, N);
        iter = shogen.begin();
        for(int j = 0; j < N; j++){
            //全員の証言を見ていく
            n = iter->second.size();
            for(int k = 0; k < n; k++){
                //証言を順番に見ていく
                if(iter->second[k].second != pattern[iter->second[k].first]){
                    //ここに入ると嘘つき
                    if(pattern[j] == 1){
                        //なのにいい人だとおかしいのでそのパターンはなし。
                        goto ptn_end;
                    }
                }
            }
            iter++;
        }
        //やり終えたら次のパタンに行く前に集計、いい人が保持値より多ければ答えを更新
        sum_ = std::accumulate(pattern.begin(), pattern.end(),0);
        if(sum_ > ans){
            ans = sum_;
        }

        ptn_end:
        ;
    }
    std::cout << ans;

}

vector<int> my_bit(int n, int keta){
    int n_loop = 0;//桁数
    int bit_buff;
    double d_n = (double)n;
    //最大桁を算出
    while(d_n >= 1.0){
        n_loop++;
        d_n = d_n/2.0;
    }

    vector<int> ans(n_loop);

    //割ってこう
    for(int i =0; i < n_loop; i++){
        bit_buff = mypow(2, (n_loop - 1 -i));
        if(n >= bit_buff){
            ans[i] = 1;
            n = n - bit_buff; 
        }
    }

    ans.insert(ans.begin(), keta - ans.size(), 0);
    return ans;
}

int mypow(int x, int y){
    int ans = 1;
    for(int i = 0; i < y; i++){
        ans = ans * x;
    }
    return ans;
}