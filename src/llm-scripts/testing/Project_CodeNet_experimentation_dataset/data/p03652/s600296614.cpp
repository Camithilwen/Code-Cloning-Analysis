//g++ -std=c++14 test.cpp -o test.out

 //全部開催すると仮定した後、1つずつ減らして調べていく

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,M;
LL A[300][300];

LL ans = INF;

void solve(){
	//i番目の人が何番目のスポーツを選んでいるかをselected_index[i]とおく
	vector<int> selected_index(N,0);
	vector<int> hold(M,1);//M番目のスポーツを開催するのかどうか
	auto max_count = [&](){
		//スポーツiを選んでいる人間の数をcounter[i]とおく
		vector<int> counter(M,0);
		for(int i=0;i<N;i++){
			if(selected_index[i]<M) counter[A[i][selected_index[i]]]++;
		}

		int max_counter = 0;//選んでる人が一番多いスポーツの人数
		int max_sports = 0;//選んでる人が一番多いスポーツの番号
		for(int i=0;i<M;i++){
			if(max_counter<counter[i]){
				max_counter = counter[i];
				max_sports = i;
			}
		}
		return pair<LL,LL>(max_counter,max_sports);
	};
	ans = max_count().first;
	for(int _=0;_<M-1;_++){
		pair<LL,LL> maxs = max_count();
		LL max_counter = maxs.first;
		LL max_sports = maxs.second;

		hold[max_sports] = 0;//選んでる人が一番多いスポーツを中止
		for(int i=0;i<N;i++){
			while(1){
				if(!hold[A[i][selected_index[i]]]) selected_index[i]++;
				else break;
			}
		}

		// cout << endl;
		// for(int i=0;i<N;i++){
		// 	for(int j=0;j<M;j++){
		// 		if(hold[A[i][j]]==1) cout << A[i][j] << " ";
		// 		else cout << "  ";
		// 	}
		// 	cout << endl;
		// }

		maxs = max_count();
		ans = min(ans,maxs.first);
	}
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
    	for(int j=0;j<M;j++){
    		cin >> A[i][j];
    		A[i][j]--;
    	}
    }

    solve();

	cout << ans << endl;
    return 0;
}