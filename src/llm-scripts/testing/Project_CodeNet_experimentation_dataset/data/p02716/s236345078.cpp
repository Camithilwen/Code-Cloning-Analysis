#include <iostream>
using namespace std;
#define el '\n'
typedef long long ll;
const int MAXN = 2e5+2;
int N, A[MAXN];
ll odd[MAXN], dp[MAXN];
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 1;i<=N;i++) cin >> A[i];
	odd[1] = A[1];
	for(int i = 2;i<=N;i++){
		if(i%2){
			odd[i] = odd[i-2]+A[i];
		}
	}
	dp[1] = 0;
	for(int i = 2;i<=N;i++){
		if(i%2){
			dp[i] = max(dp[i-2]+A[i], dp[i-1]);
		}else{
			dp[i] = max(dp[i-2]+A[i], odd[i-1]);
		}
	}
	cout << dp[N] << el;
}