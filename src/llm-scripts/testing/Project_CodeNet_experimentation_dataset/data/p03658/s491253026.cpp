#include <iostream>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<queue>
using namespace std;
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}
int main()
{
	ll();

	priority_queue<int>pq;
	int arr[1000];
	int n, k, sum = 0;
	cin >> n >> k;
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
		pq.push(arr[i]);
	}
	while (k--)
	{
		sum += pq.top();
		pq.pop();
	}
	cout << sum << endl;
}