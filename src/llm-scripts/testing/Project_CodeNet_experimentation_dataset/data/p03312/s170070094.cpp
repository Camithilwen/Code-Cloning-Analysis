//g++ -std=c++14 test.cpp -o test.out
//問題URL:
//https://atcoder.jp/contests/arc100/tasks/arc100_b

//参考：
// https://drken1215.hatenablog.com/entry/2018/08/28/193000

// ポイント：理想の状況がどういう時かを考える
// Max-minが最小になるのはどういう時？
// →PQSTどれ2つをとっても、差ができるだけ小さくなっているはず
// （あえて大きくしてもいいが、それだとMax-minが大きくなってしまう危険をはらんでいる上に、
// Max-minをもっと小さくする、といったことができない）
 
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
#include <stack>
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

LL N;
LL A[200000];

LL ans = INF;

void solve(){
	vector<LL> accum(N,A[0]);
	for(int i=1;i<N;i++) accum[i] = accum[i-1] + A[i];

	//切れ込み3箇所のうち、真ん中を決めうち
	//インデックスi番目の直後に入れることを想定
	for(int middle=1;middle<=N-3;middle++){
		auto search = [&](int left_index,int right_index){
			LL left = left_index;
			LL right = right_index-1;
			while(left+1<right){
				LL center = (left+right)/2LL;
				LL leftside = accum[center] - ((left_index==0)?0:accum[left_index-1]);
				LL rightside = accum[right_index] - accum[center];
				if(leftside==rightside) return center;
				if(leftside>rightside) right = center;
				if(leftside<rightside) left = center;
			}
			LL left_diff,right_diff;
			{
				LL leftside = accum[left] - ((left_index==0)?0:accum[left_index-1]);
				LL rightside = accum[right_index] - accum[left];
				left_diff = abs(rightside-leftside);
			}
			{
				LL leftside = accum[right] - ((left_index==0)?0:accum[left_index-1]);
				LL rightside = accum[right_index] - accum[right];
				right_diff = abs(rightside-leftside);
			}
			return (left_diff<right_diff)?left:right;
		};
		LL left = search(0,middle);
		LL right = search(middle+1,N-1);

		LL P = accum[left];
		LL Q = accum[middle] - accum[left];
		LL R = accum[right] - accum[middle];
		LL S = accum[N-1] - accum[right];
		LL cand = max(max(P,Q),max(R,S)) - min(min(P,Q),min(R,S));
		ans = min(ans,cand);
	}
}
 
int main(){
	cin >> N;
	for(int i=0;i<N;i++) cin >> A[i];
 
    solve();

	cout << ans << endl;
    return 0;
}