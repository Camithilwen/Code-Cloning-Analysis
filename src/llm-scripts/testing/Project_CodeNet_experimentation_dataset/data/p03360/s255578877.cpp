#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;


int main()
{
	int A[3], K;
	cin >> A[0] >> A[1] >> A[2] >> K;
	sort(A, A + 3);
	int ans = A[0] + A[1];
	for (int i = 0; i < K; i++) A[2] *= 2;
	ans += A[2];
	cout << ans << endl;
}
