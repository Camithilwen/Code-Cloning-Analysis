#include<cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const static int MOD = 1e9+7;

int main(){
	int N;
	scanf("%d\n", &N);
	bool is_black[2*N];
	for (int i = 0; i < 2*N; ++i){
		char tmp;
		scanf("%c", &tmp);
		is_black[i] = tmp == 'B';
	}
	bool is_left_end[2*N];
	if(!is_black[0]){
		printf("0\n");
		return 0;
	}
	is_left_end[0] = true;
	int n_right_end = 0;
	ull ans = 1;
	for (int i = 1; i < 2*N; ++i){
		is_left_end[i] = (is_black[i] ^ is_black[i-1]) ? is_left_end[i-1] : !is_left_end[i-1];
		if(!is_left_end[i]){
			//これを含めてこれより左側にある左端の数はi-n_right_end、右端の数はn_right_end+1
			if(i - n_right_end < n_right_end + 1){
				printf("0\n");
				return 0;
			}
			(ans *= i - n_right_end*2) %= MOD;
			n_right_end++;
		}
	}
	if(n_right_end != N){
		printf("0\n");
		return 0;
	}
	for (int i = 2; i <= N; ++i) (ans *= i) %= MOD;
	printf("%llu\n", ans);
	return 0;
}