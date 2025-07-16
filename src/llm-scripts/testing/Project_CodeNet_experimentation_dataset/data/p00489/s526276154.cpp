#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
	int N;
	int score[101];
	vector<int> res;
	int A, B, C, D;
	int rank[101];
	int n, r;
	
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		score[i] = 0;
	}
	for(int i = 0; i < N * (N - 1) / 2; i++){
		scanf("%d%d%d%d", &A, &B, &C, &D);
		
		if(C > D) score[A] += 3;
		else if(C < D) score[B] += 3;
		else{
			score[A]++; score[B]++;
		}
	}
	
	for(int i = 1; i <= N; i++){
		res.push_back(score[i]);
	}
	sort(res.begin(), res.end(), greater<int>());
	res.erase(unique(res.begin(), res.end()), res.end());
	n = 0;
	for(int i = 0; i < res.size(); i++){
		r = n + 1;
		for(int j = 1; j <= N; j++){
			if(res[i] == score[j]){
				rank[j] = r;
				n++;
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		printf("%d\n", rank[i]);
	}
	
	return 0;
}