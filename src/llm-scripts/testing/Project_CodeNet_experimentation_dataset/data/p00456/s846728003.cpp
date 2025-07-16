#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
	//コンテスト	

	int W[10], K[10];
	for (int i = 0; i < 10; i++) {
		cin >> W[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> K[i];
	}
	sort(W, W + 10);
	reverse(W, W + 10);
	sort(K, K + 10);
	reverse(K, K + 10);
	cout << W[0] + W[1] + W[2] << " " << K[0] + K[1] + K[2] << endl;

	//ポイントカード
	/*
	int N, M;
	cin >> N >> M;
	int a;
	int A[5000];
	int b = 0;
	int x = 0;
	for (int i = 0; i <  M; i++) {
		cin >> a;
		if (a < N) {
			A[x]=a;
			x++;
		}
		else
		{
			b++;
		} 
		cin >> a;
	}
	int sum = 0;
	if (b < M - 1) {
		sort(A, A+x);
		reverse(A, A+x);
		for (int i = 0; i < M - 1 - b; i++) {
			sum += N - A[i];
		}
	}
	cout << sum << endl;
	*/

	//合計時間
	/*
	int sum=0, n;
	for (int i = 0; i < 4; i++) {
	cin >> n;
	sum += n;
	}
	cout << sum / 60 << endl;
	cout << sum % 60 << endl;
	//平均点
	/*
	int P[5];
	int sum=0;
	for (int i = 0; i < 5; i++) {
	cin >> P[i];
	if (P[i] < 40) P[i] = 40;
	sum += P[i];
	}
	cout << sum / 5 << endl;
	*/
	//投票
	/*
	int N, M;
	cin >> N >> M;
	int A[1000], vote[1000];
	for (int i = 0; i < N; i++) {
	cin >> A[i];
	vote[i] = 0;
	}
	int b;
	for (int i = 0; i < M; i++) {
	cin >> b;
	for (int j = 0; j < N; j++) {
	if (A[j] <= b) {
	vote[j]++;
	break;
	}
	}
	}
	int temps = 0, ans;
	for (int i = 0; i < N; i++) {
	if (vote[i] > temps) {
	temps = vote[i];
	ans = i;
	}
	}
	cout << ans + 1 << endl;
	*/

	//2.すごろく	
	/*
	int n;
	cin >> n;
	int A, _A = 1;
	int k = 0;
	int A_count[100];
	A_count[0] = 1;
	for (int i = 0; i < n; i++)
	{
	cin >> A;
	if (A == 1)
	{
	if (A == _A)
	{
	A_count[k]++;
	}
	else
	{
	k++;
	A_count[k] = 2;
	}
	}
	_A = A;
	}
	sort(A_count, A_count + k + 1);
	cout << A_count[k] << endl;
	*/

	//タイムカード
	/*
	int t[2][3];
	int x[3][3];
	for (int n=0; n < 3; n++)
	{
	for (int i=0; i < 2; i++)
	for (int k=0; k < 3; k++)
	cin >> t[i][k];

	for (int m = 2; m >= 0; m--)
	{
	x[n][m] = t[1][m] - t[0][m];
	if (t[0][m] > t[1][m])
	{
	x[n][m] += 60;
	t[1][m - 1]--;
	}
	}
	}
	for (int n= 0; n < 3; n++)
	{
	cout << x[n][0] << ' ' << x[n][1] <<' '<< x[n][2] << endl;
	}
	*/



	return 0;
}
