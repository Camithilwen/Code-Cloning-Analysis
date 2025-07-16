#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

long long  N, K;
vector<long long> x;

long long calcTime(int i, int k){
	if(k <= 1) return 0;

	long long rt = (1L<<61), lt = (1L<<61);

	int Rk = N - i - 1; //x[i]より右にある本数
	int Lk = i;         //x[i]より左にある本数

	//右に行ってから左へ
	for(int j = K - i - 1; j <= Rk; j++){
		if(i + j >= N || j < 0) continue;
		long long t = x[i + j] - x[i]; //右の端までの時間
		t *= 2; //x[i]まで戻ってくる
		t += x[i] - x[i - (K - j - 1)];//左の端まで
		if(t < rt) rt = t;
	}

	//左に行ってから右へ
	for(int j = K- N + i; j <= Lk; j++){
		if(i < j || j < 0) continue;;
		long long t = x[i] - x[i - j]; //左の端までの時間
		t *= 2; //x[i]まで戻ってくる
		t += x[i + (K - j - 1)] - x[i];//右の端まで
		if(t < lt) lt = t;
	}
	return (long long) min(rt, lt);
}

int main(int argc, char* argv[]){
	cin >> N >> K;
	for(int i=1; i<=N; i++){
		long long u;
		cin >> u;
		x.push_back(u);
	}
	//入力はソート済だが念のためソートする
	sort(x.begin(), x.end());

	long long ans = 0;
	if(x[0] >= 0){
		ans = (long long)abs(x[K-1]);
		printf("%lld\n", ans);
		return 0;
	}
	else if(x[N-1] <= 0){
		ans = (long long)abs(x[N-K]);
		printf("%lld\n", ans);
		return 0;
	}
	int a, b;
	for(int i=0; i<N; i++){
		if(x[i] > 0){ break; }
		a = i;
	}
	for(int i=N-1; i>=0; i--){
		if(x[i] < 0){ break; }
		b = i;
	}
	long long ans_a = abs(x[a]) + calcTime(a, K);
	long long ans_b = abs(x[b]) + calcTime(b, K);
	ans = min( ans_a, ans_b);
	printf("%lld\n", ans);
	return 0;
}