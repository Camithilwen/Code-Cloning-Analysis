#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> query;
    for(int i=0;i<q;++i){
        int k;
        cin >> k;
        query.push_back(k);
    }

    vector<int> cumsum_c(n+1, 0), cumsum_m(n+1, 0);
    vector<pair<int, int>> idx_c;
    vector<pair<char, int>> idx_dc;
    for(int i=0;i<n;++i){
        cumsum_c[i+1] = cumsum_c[i];
        cumsum_m[i+1] = cumsum_m[i];
        if(s[i] == 'D'){
            idx_dc.emplace_back('D', i);
        }else if(s[i] == 'M'){
            cumsum_m[i+1]++;
        }else if(s[i] == 'C'){
            cumsum_c[i+1]++;
            idx_c.emplace_back(i, (int)idx_dc.size());
            idx_dc.emplace_back('C', i);
        }
    }

    for(auto k: query){
        i64 ans = 0, num_c = 0, num_d = 0;
        vector<int> imos(idx_dc.size());
        for(int i=0;i<idx_dc.size();++i){
            if(idx_dc[i].first == 'D'){
                if(i > 0){
                    ans += num_c * (cumsum_m[idx_dc[i].second]-cumsum_m[idx_dc[i-1].second+1]);
                }
                int valid = -1, invalid = (int)idx_c.size();
                while(invalid-valid > 1){
                    int mid = (valid + invalid) / 2;
                    if(idx_c[mid].first < idx_dc[i].second + k)valid = mid;
                    else invalid = mid;
                }
                if(valid < 0)continue;
                i64 c = cumsum_c[idx_c[valid].first+1] - cumsum_c[idx_dc[i].second];
                //cerr << c << endl;
                c = max(c, (i64)0);
                num_c += c;
                num_d++;
                imos[idx_c[valid].second]++;
                //cerr << num_c << endl;
            }else{
                if(i == 0)continue;
                ans += num_c * (cumsum_m[idx_dc[i].second]-cumsum_m[idx_dc[i-1].second+1]);
                num_c -= num_d;
                num_d -= imos[i];
            }
            //cerr << ans << endl;
        }
        cout << ans << endl;
    }

    return 0;
}