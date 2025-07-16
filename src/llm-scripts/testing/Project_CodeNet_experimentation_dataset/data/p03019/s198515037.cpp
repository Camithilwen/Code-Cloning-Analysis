#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>

using namespace std;

long long PRIME = 1000000007;


struct info{
    long long b;
    long long l;
    long long u;
    long long d_max;
};


bool comp(const info& l, const info& r){
    return l.d_max > r.d_max;
}


vector<info> info_vec;
vector<long long> sum_vec;
long long X;
long long N;


long long checkX(long long S){
    long long num = S / X;
    long long rest = S % X;

    if(rest == 0){
        return sum_vec[num];
    }

    long long ret = -1;

    for(int i = 0; i < N; ++i){
        long long val;

        if(i < num){
            val = sum_vec[num + 1];
            val -= info_vec[i].d_max;
        }
        else{
            val = sum_vec[num];
        }

        if(rest < info_vec[i].b){
            val += info_vec[i].l * rest;
        }
        else{
            val += info_vec[i].l * info_vec[i].b + info_vec[i].u * (rest - info_vec[i].b);
        }

        ret = max(ret, val);
    }

    return ret;
}


int main(int argc, char* argv[]){
    cin >> N >> X;

    info_vec.resize(N);
    sum_vec.resize(N + 1);

    long long b;
    long long l;
    long long u;

    long long cost_zero = 0;

    for(int i = 0; i < N; ++i){
        cin >> b >> l >> u;

        info_vec[i].b = b;
        info_vec[i].u = u;
        info_vec[i].l = l;
        info_vec[i].d_max = (X - b) * u + b * l;

        cost_zero -= l * b;
    }

    if(cost_zero == 0){
        cout << 0;
        return 0;
    }
    
    std::sort(info_vec.begin(), info_vec.end(), comp);

    sum_vec[0] = cost_zero;
    for(int i = 1; i <= N; ++i){
        sum_vec[i] = sum_vec[i-1] +info_vec[i-1].d_max;
    }

    long long min_X = 0;
    long long max_X = X * N;
    long long mid_X;
    long long cost;

    while(max_X - min_X > 1){
        mid_X = (min_X + max_X) / 2;

        cost = checkX(mid_X);

        if(cost < 0){
            min_X = mid_X;
        }
        else{
            max_X = mid_X;
        }
    }

    cout << max_X;

}
